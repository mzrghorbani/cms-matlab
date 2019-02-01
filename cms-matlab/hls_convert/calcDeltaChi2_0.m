function [ dChi2_0 ] = calcDeltaChi2_0(res, RmatInv)

    dChi2_0 = res' * RmatInv * res;
    
end