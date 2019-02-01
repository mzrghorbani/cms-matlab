//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixV.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 18:27:26
//

// Include Files
#include "rt_nonfinite.h"
#include "MatrixV.h"
#include "PitchOverR.h"

// Function Definitions

//
// Arguments    : double r
//                double z
//                double inv2R
//                double tanL
//                double V[4]
// Return Type  : void
//
void MatrixV(double r, double z, double inv2R, double tanL, double V[4])
{
  double pitchPSoverR;
  double pitch2SoverR;
  double absZ;
  boolean_T b_absZ;
  V[2] = 0.0;
  V[1] = 0.0;

  //  Digitisation multipliers (from data format doc).
  //  Used for r & z in KF.
  //  Numbers from http://ghugo.web.cern.ch/ghugo/layouts/July/OT613_200_IT4025/layout.html 
  //  Module pitch for tilted tracker geometry divided by sqrt(12) to get resolution. 
  //  invRoot12  = 1/sqrt(12);
  //  1/sqrt(12)
  //  IRT: Declaring these static causes cosimulation to set them to zero. Why?
  //  But it is OK if invRoot12 is defined as 0.288 instead of 1/sqrt(12.)
  //  < 1024
  //  IRT
  //  lengthPS   = rMult*invRoot12*0.15;
  //  Factor 1.41 allows for digitisation granularity (Sioni).
  //  < 16
  //  Slight variants on length that Sioni found improved performance.
  //  These boundaries are for tilted tracker geometry.
  //  Largest z in barrel.
  //  Largest z of endcap wheels 1 or 2.
  //  r of PS-2S transition in barrel.
  //  r below which stub certain to be PS if in endcap wheels 1 or 2.
  //  r below which stub certain to be PS if in endcap wheels 3, 4 or 5.
  //  Inverse r.
  //  static const PitchOverR calcPitchPSoverR(pitchPS);
  //  static const PitchOverR calcPitch2SoverR(pitch2S);
  //  calcPitchPSoverR = PitchOverRClass(pitchPS);
  //  calcPitch2SoverR = PitchOverRClass(pitch2S);
  //  PitchOverR::TPOR pitchPSoverR = calcPitchPSoverR.get[r.to_uint() >> PitchOverR::BRED]; 
  //  PitchOverR::TPOR pitch2SoverR = calcPitch2SoverR.get[r.to_uint() >> PitchOverR::BRED]; 
  //  pitchPSoverR = calcPitchPSoverR.get(r(1));
  //  pitch2SoverR = calcPitch2SoverR.get(r(1));
  pitchPSoverR = PitchOverR(592.47943413231394, r);
  pitch2SoverR = PitchOverR(532.63302664420132, r);

  //    #ifdef PRINT_SUMMARY
  //    CHECK_AP::checkCalc("p/r", pitch2SoverR, double(pitch2S)/double(r));
  //    #endif
  //    #ifdef PRINT
  //    std::cout<<"Inverse R check "<<r<<" "<<(double(r)*double(inverseR))<<std::endl; 
  //    #endif
  absZ = z;

  //  HLS has no abs() function.
  if (z < 0.0) {
    absZ = -z;
  }

  //  Use same granularity for resolution as for residuals.
  //  (Define as signed, so dont have to worry if tanL or inv2R are -ve).
  //    sigmaPhi;
  //    sigmaPhiExtra;
  //    sigmaZ;
  if (absZ < 1242.25) {
    //  Barrel
    //  #ifdef PRINT
    //      std::cout<<"BARREL "<<absZ<<" "<<zBarrel<<std::endl;
    //  #endif
    if (r < 596.28000000000009) {
      //  _2Smodule = false;
      pitch2SoverR = pitchPSoverR;
      absZ = 0.606762229725;
    } else {
      //  _2Smodule = true;
      absZ = 14.401637793;
    }

    pitchPSoverR = 0.0;
  } else {
    //  Endcap
    //  psEndcap=(absZ < zWheel12)?(r < rPSwheel12):(r < rPSwheel345);
    if (absZ < 1689.46) {
      b_absZ = (r < 659.8832000000001);
    } else {
      b_absZ = (r < 641.99479999999994);
    }

    if (b_absZ) {
      //  #ifdef
      //        std::cout<<"ENDCAP1 "<<tanL<<std::endl;
      //  #endif
      //  _2Smodule = false;
      pitch2SoverR = pitchPSoverR;
      pitchPSoverR = 0.63710034121125 * inv2R;
      absZ = 0.54608600675250007 * tanL;
    } else {
      //  #ifdef PRINT
      //  std::cout<<"ENDCAP2 "<<tanL<<std::endl;
      //  #endif
      //  _2Smodule = true;
      pitchPSoverR = 15.121719682650001 * inv2R;
      absZ = 12.9614740137 * tanL;
    }
  }

  //  IRT - add scattering to improve efficiency. Should also add phi digitisation error! 
  //  static const AP_FIXED(B18,BSP) sigmaPhiScat = 0.0003*phiMult;
  //  v_00 = sigmaPhi*sigmaPhi + sigmaPhiExtra*sigmaPhiExtra + sigmaPhiScat*sigmaPhiScat; 
  //  v_00 = sigmaPhi*sigmaPhi + sigmaPhiExtra*sigmaPhiExtra;
  V[0] = pitch2SoverR * pitch2SoverR + pitchPSoverR * pitchPSoverR;
  V[3] = absZ * absZ;

  //  #ifdef PRINT
  //    std::cout<<"PS = "<<(double(sigmaZ) > -double(rMult) && double(sigmaZ) < double(rMult))<<" (r,z) "<<r<<" "<<z<<std::endl; 
  //    std::cout<<"SIGMA "<<sqrt(double(_00))/double(phiMult)<<" "<<sqrt(double(_11))/double(rMult)<<std::endl; 
  //    std::cout<<"  V00 = "<<_00<<"   V11 = "<<_11<<std::endl;
  //  #endif
  //  static const float rats = sqrt(2.9713); // FAIL
  //  static const AP_UFIXED(40,20) length2ST   = rats;
  //  v_11 = length2ST;
  //  static const float rats = 3./2.; // GOOD
  //  static const AP_UFIXED(40,20) length2ST   = rats;
  //  v_11 = length2ST;
  //  static const float rats = sqrt(2.9713); // GOOD
  //  const AP_UFIXED(40,20) length2ST   = rats;
  //  v_11 = length2ST;
  //  static const float rats = sqrt(2.9713); // GOOD
  //  v_11 = rats;
}

//
// File trailer for MatrixV.cpp
//
// [EOF]
//
