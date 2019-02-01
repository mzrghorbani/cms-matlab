clear all;
close all;

% Variables
BSR = 11;
BSP = 14; 
cBin = 0;
mBin = 1;
inv2R = 0; 
cov_00 = 0;
cov_11 = 0;
cov_22 = 0;
cov_33 = 0;
cov_01 = 0;
cov_23 = 0;
chiSquared = 0;
% layerID = 0;
% nSkippedLayers = 0;
% candidateID = 0;
% eventID = 0;
% etaSectorID = 0;
% etaSectorZsign = 0;

rMult = pow2(BSR-1) / 103.0382 ;
phiMult = pow2(BSP) / 0.78539816340;
rphiMult = rMult * phiMult;
inv2R_Mult = phiMult / rMult;
bField = 3.8112;
invPtToInvR = bField * (3e+8 / 1e+11);

%% Track

invPt = 1/3;
phi0 = 0.1;
tanL = -3.8;
z0 = -5;

%% Uncertainty in track seed

sigma_invPt = 0.0157 * 2;
sigma_phi0 = 0.0051 * 2;
sigma_tanL = 0.25;
sigma_z0 = 5;

%% Error in track seed

err_invPt = 0.5 * sigma_invPt;
err_phi0 = 0 * sigma_phi0;
err_tanL = 0 * sigma_tanL;
err_z0 = -0.5 * sigma_z0;

%% Stubs

nStub = 3;

r = [23, 37, 80];
z = zeros(1,3);
phiS = zeros(1,3);

for i = 1:3
    z(i) = z0 + (r(i) * tanL);
    phiS(i) = phi0 - (0.5 * invPtToInvR * invPt * r(i));
end

stub = struct('r', {r}, 'z', {z}, 'phiS', {phiS});
      
stateOut = struct('cBin', {cBin}, 'mBin', {mBin}, 'inv2R', {inv2R},...
    'phi0', {phi0}, 'tanL', {tanL}, 'z0', {z0}, 'cov_00', {cov_00},...
        'cov_11', {cov_11}, 'cov_22', {cov_22}, 'cov_33', {cov_33},...
            'cov_01', {cov_01}, 'cov_23', {cov_23}, 'chiSquared', {chiSquared});

%% 

for j = 1:1:3
    
    fprintf('-------------Iteration %d\n', j);
    stub.r = floor(rMult * r(j));
    stub.z = floor(rMult * z(j));
    stub.phiS = floor(phiMult * phiS(j));
    
    stateIn = struct('cBin', {cBin}, 'mBin', {mBin}, 'inv2R', {inv2R},...
        'phi0', {phi0}, 'tanL', {tanL}, 'z0', {z0}, 'cov_00', {cov_00},...
            'cov_11', {cov_11}, 'cov_22', {cov_22}, 'cov_33', {cov_33},...
                'cov_01', {cov_01}, 'cov_23', {cov_23}, 'chiSquared', {chiSquared}); 
    
    if (j == 1)
        
        stateIn.chiSquared = 0;
        stateIn.inv2R = (0.5 * invPtToInvR * (invPt + err_invPt)) * inv2R_Mult;
        stateIn.phi0 = (phi0 + err_phi0) * phiMult;
        stateIn.tanL = tanL + err_tanL;
        stateIn.z0 = (z0 + err_z0) * rMult;
        stateIn.cov_00 = ((0.5 * invPtToInvR) * inv2R_Mult * sigma_invPt)^2;
        stateIn.cov_11 = (phiMult * sigma_phi0)^2;
        stateIn.cov_22 = sigma_tanL^2;
        stateIn.cov_33 = (rMult * sigma_z0)^2;
        stateIn.cov_01 = 0;
        stateIn.cov_23 = 0;
        
    else
        stateIn = stateOut;
    end
        
        % stateIn.LayerID = j + 1;
        % stateIn.nSkippedLayers = 0;
        % stateIn.candidateID = 3;
        % stateIn.eventID = 2;
        % stateIn.etaSectorID = 1;
        % stateIn.etaSectorZsign = false;
        % stateIn.valid = true;

        stateOut = KalmanUpdateHLS(stub, stateIn);
        
        chi2_out = stateOut.chiSquared;
        invPt_out = stateOut.inv2R / inv2R_Mult / (0.5 * invPtToInvR);
        phi0_out  = stateOut.phi0 / phiMult;
        tanL_out = stateOut.tanL;
        z0_out = stateOut.z0 / rMult;
        sigma_invPt_out = sqrt(stateOut.cov_00) / (inv2R_Mult *(0.5 * invPtToInvR));
        sigma_phi0_out  = sqrt(stateOut.cov_11) / phiMult;
        sigma_tanL_out  = sqrt(stateOut.cov_22);
        sigma_z0_out = sqrt(stateOut.cov_33) / rMult;

        % IRT
        cov01_out = stateOut.cov_01 / (inv2R_Mult * (0.5 * invPtToInvR) * phiMult);
        corr01_out = cov01_out / (sigma_invPt_out * sigma_phi0_out);
        cov23_out = stateOut.cov_23 / rMult;
        corr23_out = cov23_out / (sigma_tanL_out*sigma_z0_out);                 
end