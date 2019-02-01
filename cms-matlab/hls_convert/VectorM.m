function [ m ] = VectorM(phiS, z)

    m = zeros(2,1);
    m(1,1) = phiS(1);
    m(2,1) = z(1);
    
end


