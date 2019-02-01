function [ H ] = MatrixH( r )
    
    H = zeros(2,4);
    H(1,1) = -r;
    H(1,2) = 1;
    H(1,3) = 0;
    H(1,4) = 0;
    H(2,1) = 0;
    H(2,2) = 0;
    H(2,3) = r;
    H(2,4) = 1;

end

