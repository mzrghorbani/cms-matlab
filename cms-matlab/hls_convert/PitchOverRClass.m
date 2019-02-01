classdef PitchOverRClass
    %UNTITLED2 Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        get = zeros(1,512)
    end
    
    methods (Static)
        function obj = PitchOverRClass(pitch)
            BEX = 0;
            BSR = 11;
            BRED = 2 + BEX;
            MAXN = 2^(BSR-BRED);
            
            for n=3:1:MAXN-1  % Don't bother initializing first two, as would overflow bit range.
                obj.get(n) = pitch / (bitsll(n, BRED)) + (0.5*bitsll(1, BRED)); % Round to nearest half integer
            end
        end
    end
end

