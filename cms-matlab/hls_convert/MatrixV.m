function [V] = MatrixV(r, z, inv2R, tanL)
    V = zeros(2);
    V(1,2) = 0;
    V(2,1) = 0;
    BEX = 0;
    % Digitisation multipliers (from data format doc).
    rMult = 9.938 * 2^BEX; % Used for r & z in KF.
    phiMult = 20860.75;
    rphiMult = rMult * phiMult;
    % Numbers from http://ghugo.web.cern.ch/ghugo/layouts/July/OT613_200_IT4025/layout.html
    % Module pitch for tilted tracker geometry divided by sqrt(12) to get resolution.
    % invRoot12  = 1/sqrt(12);
    invRoot12  = 0.288675; % 1/sqrt(12)
    % IRT: Declaring these static causes cosimulation to set them to zero. Why?
    % But it is OK if invRoot12 is defined as 0.288 instead of 1/sqrt(12.)
    pitchPS = rphiMult * invRoot12 * 0.0099;  % < 1024
    pitch2S = rphiMult * invRoot12 * 0.0089;
    % IRT 
    % lengthPS   = rMult*invRoot12*0.15;
    lengthPS = 1.41*rMult * invRoot12 * 0.15; % Factor 1.41 allows for digitisation granularity (Sioni).
    length2S = rMult * invRoot12 * 5.02;       % < 16
    % Slight variants on length that Sioni found improved performance.
    lengthPS105 = 1.05 * lengthPS;
    length2S105 = 1.05 * length2S;
    lengthPS09  = 0.9 * lengthPS;
    length2S09  = 0.9 * length2S;

    % These boundaries are for tilted tracker geometry.
    zBarrel = rMult * 125; % Largest z in barrel.
    zWheel12 = rMult * 170; % Largest z of endcap wheels 1 or 2.
    rPSbarrel = rMult * 60.0;  % r of PS-2S transition in barrel.
    rPSwheel12 = rMult * 66.4; % r below which stub certain to be PS if in endcap wheels 1 or 2.
    rPSwheel345 = rMult * 64.6; % r below which stub certain to be PS if in endcap wheels 3, 4 or 5.
    
    % Inverse r.
    % static const PitchOverR calcPitchPSoverR(pitchPS);
    % static const PitchOverR calcPitch2SoverR(pitch2S);
    % calcPitchPSoverR = PitchOverRClass(pitchPS);
    % calcPitch2SoverR = PitchOverRClass(pitch2S);
    
    % PitchOverR::TPOR pitchPSoverR = calcPitchPSoverR.get[r.to_uint() >> PitchOverR::BRED];
    % PitchOverR::TPOR pitch2SoverR = calcPitch2SoverR.get[r.to_uint() >> PitchOverR::BRED];
    
    % pitchPSoverR = calcPitchPSoverR.get(r(1));
    % pitch2SoverR = calcPitch2SoverR.get(r(1));
    
    pitchPSoverR = PitchOverR(pitchPS, r);
    pitch2SoverR = PitchOverR(pitch2S, r);
    
    %   #ifdef PRINT_SUMMARY
    %   CHECK_AP::checkCalc("p/r", pitch2SoverR, double(pitch2S)/double(r));
    %   #endif
    %   #ifdef PRINT
    %   std::cout<<"Inverse R check "<<r<<" "<<(double(r)*double(inverseR))<<std::endl;
    %   #endif

    absZ = z;   % HLS has no abs() function.

    if (z(1) < 0)
        absZ = -z;
    end
  
    % Use same granularity for resolution as for residuals.
    % (Define as signed, so dont have to worry if tanL or inv2R are -ve).
    %   sigmaPhi;
    %   sigmaPhiExtra;
    %   sigmaZ;

  if (absZ(1) < zBarrel)
    % Barrel
    % #ifdef PRINT
    %     std::cout<<"BARREL "<<absZ<<" "<<zBarrel<<std::endl;
    % #endif
      if (r(1) < rPSbarrel)
          % _2Smodule = false;
          sigmaPhi = pitchPSoverR;
          sigmaZ   = lengthPS;
      else
          % _2Smodule = true;
          sigmaPhi = pitch2SoverR;
          sigmaZ   = length2S;
      end
         sigmaPhiExtra = 0;
  else

    % Endcap
    % psEndcap=(absZ < zWheel12)?(r < rPSwheel12):(r < rPSwheel345);
    if(absZ < zWheel12)
        psEndcap = r < rPSwheel12;
    else
        psEndcap = r < rPSwheel345;
    end

        if (psEndcap == 1)
            % #ifdef 
            %       std::cout<<"ENDCAP1 "<<tanL<<std::endl;
            % #endif
            % _2Smodule = false;
            sigmaPhi = pitchPSoverR;
            sigmaPhiExtra = lengthPS105*inv2R;
            sigmaZ = lengthPS09*tanL;
        else
            % #ifdef PRINT
            % std::cout<<"ENDCAP2 "<<tanL<<std::endl;

            % #endif
            % _2Smodule = true;
            sigmaPhi = pitch2SoverR;
            sigmaPhiExtra = length2S105*inv2R;
            sigmaZ = length2S09*tanL;

        end
  end
    % IRT - add scattering to improve efficiency. Should also add phi digitisation error!
    % static const AP_FIXED(B18,BSP) sigmaPhiScat = 0.0003*phiMult;
    % v_00 = sigmaPhi*sigmaPhi + sigmaPhiExtra*sigmaPhiExtra + sigmaPhiScat*sigmaPhiScat;
    % v_00 = sigmaPhi*sigmaPhi + sigmaPhiExtra*sigmaPhiExtra;
    V(1,1) = sigmaPhi*sigmaPhi + sigmaPhiExtra*sigmaPhiExtra;
    V(2,2) = sigmaZ*sigmaZ;
    % #ifdef PRINT
    %   std::cout<<"PS = "<<(double(sigmaZ) > -double(rMult) && double(sigmaZ) < double(rMult))<<" (r,z) "<<r<<" "<<z<<std::endl;
    %   std::cout<<"SIGMA "<<sqrt(double(_00))/double(phiMult)<<" "<<sqrt(double(_11))/double(rMult)<<std::endl;
    %   std::cout<<"  V00 = "<<_00<<"   V11 = "<<_11<<std::endl;
    % #endif

    % static const float rats = sqrt(2.9713); // FAIL
    % static const AP_UFIXED(40,20) length2ST   = rats;
    % v_11 = length2ST;

    % static const float rats = 3./2.; // GOOD
    % static const AP_UFIXED(40,20) length2ST   = rats;
    % v_11 = length2ST;

    % static const float rats = sqrt(2.9713); // GOOD
    % const AP_UFIXED(40,20) length2ST   = rats;
    % v_11 = length2ST;

    % static const float rats = sqrt(2.9713); // GOOD
    % v_11 = rats;  
end