function [ y ] = PitchOverR(pitch, r)
     
    get = zeros(1,512);
    
    for n = 3 : 511
      get(n) = pitch/(bitsll(n,2) + 0.5*bitsll(1,2));
    end
    
    y = get(round(r/4));
    
end
