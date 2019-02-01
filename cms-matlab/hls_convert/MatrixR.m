function [ Rmat ] = MatrixR(V, H, St)

    Rmat = V + H * St;
    
end


