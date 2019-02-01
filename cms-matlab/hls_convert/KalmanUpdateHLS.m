function [stateOut] = KalmanUpdateHLS(stub, stateIn)

    stateOut.cBin = stateIn.cBin;
    stateOut.mBin = stateIn.mBin;
    % stateOut.layerID = stateIn.layerID;
    % stateOut.nSkippedLayers = stateIn.nSkippedLayers;
    % stateOut.candidateID = stateIn.candidateID;
    % stateOut.eventID = stateIn.eventID;
    % stateOut.etaSectorID = stateIn.etaSectorID;
    % stateOut.etaSectorZsign = stateIn.etaSectorZsign;
    % stateOut.valid = (stateIn.valid && stateIn.valid);
    
    % Store vector of stub coords.
    m = VectorM(stub.phiS, stub.z);
    
    % Store covariance matrix of stub coords.
    V = MatrixV(stub.r, stub.z, stateIn.inv2R, stateIn.tanL);
    
    % Store vector of input helix params.
    x = VectorX(stateIn.inv2R, stateIn.phi0, stateIn.tanL, stateIn.z0);
    
    % Store covariance matrix of input helix params.
    C = MatrixC(stateIn.cov_00, stateIn.cov_11, stateIn.cov_22, stateIn.cov_33, stateIn.cov_01, stateIn.cov_23);
    
    % Calculate matrix of derivatives of predicted stub coords w.r.t. helix params.
    H = MatrixH(stub.r);
    
    % Calculate S = H*C, and its transpose St, which is equal to C*H(transpose).
    S = MatrixS(H, C);
    St = MatrixS_transpose(S);
    
    % Calculate covariance matrix of predicted residuals R = V + H*C*Ht = V + H*St, and its inverse.
    % (Call this Rmat instead of R to avoid confusion with track radius).
    Rmat = MatrixR(V, H, St);
    RmatInv = MatrixInverseR(Rmat);
    
    % Calculate Kalman gain matrix * determinant(R): K = S*R(inverse)
    K = MatrixK(St, RmatInv);
    
    % Calculate hit residuals.
    res = VectorRes(m, H, x);
    
    % Calculate output helix params & their covariance matrix.
    x_new = VectorX_1(x, K, res); 
    C_new = MatrixC_1(C, K, S);

    % Calculate increase in chi2 from adding new stub: delta(chi2) = res(transpose) * R(inverse) * res
    deltaChi2 = calcDeltaChi2_0(res, RmatInv);
    chi2 = stateIn.chiSquared + deltaChi2;
    
    % Truncate chi2 to avoid overflow.
    MAX_CHI2 = (1^10) - 1;
     
    if (chi2 > MAX_CHI2)
        chi2 = MAX_CHI2;
    end
        
    stateOut.chiSquared = chi2;
    stateOut.inv2R = x_new(1);
    stateOut.phi0  = x_new(2);
    stateOut.tanL  = x_new(3);
    stateOut.z0    = x_new(4);
    stateOut.cov_00 = C_new(1,1);
    stateOut.cov_11 = C_new(2,2);
    stateOut.cov_22 = C_new(3,3);
    stateOut.cov_33 = C_new(4,4);
    stateOut.cov_01 = C_new(1,2);
    stateOut.cov_23 = C_new(3,4);
    
end