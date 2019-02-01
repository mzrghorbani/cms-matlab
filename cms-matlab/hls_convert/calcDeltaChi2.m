function [ dChi2 ] = calcDeltaChi2(res, RmatInv)

    % delta(chi2) = res(transpose) * R(inverse) * res
    % dChi2 = res' * RmatInv * res;
    dChi2 = (res(1) * res(1)) * RmatInv(1,1) + ...
            (res(2) * res(2)) * RmatInv(2,2) + ... 
        2 * (res(1) * res(2)) * RmatInv(1,2);
    
end

