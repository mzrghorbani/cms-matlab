function [ x ] = VectorX(inv2R, phi0, tanL, z0)
 
    % _0(inv2R), _1(phi0), _2(tanL), _3(z0)
    x = zeros(4,1);
    x(1,1) = inv2R;
    x(2,1) = phi0;
    x(3,1) = tanL;
    x(4,1) = z0;

end