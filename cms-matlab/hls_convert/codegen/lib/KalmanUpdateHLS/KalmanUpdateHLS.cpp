//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: KalmanUpdateHLS.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 19:22:55
//

// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "KalmanUpdateHLS.h"
#include "PitchOverR.h"

// Function Definitions

//
// Arguments    : const struct0_T *stub
//                const struct1_T *stateIn
//                struct1_T *stateOut
// Return Type  : void
//
void KalmanUpdateHLS(const struct0_T *stub, const struct1_T *stateIn, struct1_T *
                     stateOut)
{
  double m[2];
  double V[4];
  double pitchPSoverR;
  double pitch2SoverR;
  double absZ;
  boolean_T b_absZ;
  double x[4];
  double C[16];
  double H[8];
  int i0;
  int i1;
  double S[8];
  int i2;
  double Rmat[4];
  double St[8];
  double RmatInv[4];
  double K[8];
  double res[2];
  double C_new[16];
  stateOut->cBin = stateIn->cBin;
  stateOut->mBin = stateIn->mBin;

  //  stateOut.layerID = stateIn.layerID;
  //  stateOut.nSkippedLayers = stateIn.nSkippedLayers;
  //  stateOut.candidateID = stateIn.candidateID;
  //  stateOut.eventID = stateIn.eventID;
  //  stateOut.etaSectorID = stateIn.etaSectorID;
  //  stateOut.etaSectorZsign = stateIn.etaSectorZsign;
  //  stateOut.valid = (stateIn.valid && stateIn.valid);
  //  Store vector of stub coords.
  m[0] = stub->phiS;
  m[1] = stub->z;

  //  Store covariance matrix of stub coords.
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
  pitchPSoverR = PitchOverR(592.47943413231394, stub->r);
  pitch2SoverR = PitchOverR(532.63302664420132, stub->r);

  //    #ifdef PRINT_SUMMARY
  //    CHECK_AP::checkCalc("p/r", pitch2SoverR, double(pitch2S)/double(r));
  //    #endif
  //    #ifdef PRINT
  //    std::cout<<"Inverse R check "<<r<<" "<<(double(r)*double(inverseR))<<std::endl; 
  //    #endif
  absZ = stub->z;

  //  HLS has no abs() function.
  if (stub->z < 0.0) {
    absZ = -stub->z;
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
    if (stub->r < 596.28000000000009) {
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
      b_absZ = (stub->r < 659.8832000000001);
    } else {
      b_absZ = (stub->r < 641.99479999999994);
    }

    if (b_absZ) {
      //  #ifdef
      //        std::cout<<"ENDCAP1 "<<tanL<<std::endl;
      //  #endif
      //  _2Smodule = false;
      pitch2SoverR = pitchPSoverR;
      pitchPSoverR = 0.63710034121125 * stateIn->inv2R;
      absZ = 0.54608600675250007 * stateIn->tanL;
    } else {
      //  #ifdef PRINT
      //  std::cout<<"ENDCAP2 "<<tanL<<std::endl;
      //  #endif
      //  _2Smodule = true;
      pitchPSoverR = 15.121719682650001 * stateIn->inv2R;
      absZ = 12.9614740137 * stateIn->tanL;
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
  //  Store vector of input helix params.
  //  _0(inv2R), _1(phi0), _2(tanL), _3(z0)
  x[0] = stateIn->inv2R;
  x[1] = stateIn->phi0;
  x[2] = stateIn->tanL;
  x[3] = stateIn->z0;

  //  Store covariance matrix of input helix params.
  C[0] = stateIn->cov_00;
  C[5] = stateIn->cov_11;
  C[10] = stateIn->cov_22;
  C[15] = stateIn->cov_33;
  C[4] = stateIn->cov_01;
  C[14] = stateIn->cov_23;
  C[8] = 0.0;
  C[12] = 0.0;
  C[9] = 0.0;
  C[13] = 0.0;
  C[1] = stateIn->cov_01;
  C[11] = stateIn->cov_23;
  C[2] = 0.0;
  C[3] = 0.0;
  C[6] = 0.0;
  C[7] = 0.0;

  //  Calculate matrix of derivatives of predicted stub coords w.r.t. helix params. 
  H[0] = -stub->r;
  H[2] = 1.0;
  H[4] = 0.0;
  H[6] = 0.0;
  H[1] = 0.0;
  H[3] = 0.0;
  H[5] = stub->r;
  H[7] = 1.0;

  //  Calculate S = H*C, and its transpose St, which is equal to C*H(transpose). 
  for (i0 = 0; i0 < 2; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      S[i0 + (i1 << 1)] = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        S[i0 + (i1 << 1)] += H[i0 + (i2 << 1)] * C[i2 + (i1 << 2)];
      }

      St[i1 + (i0 << 2)] = S[i0 + (i1 << 1)];
    }
  }

  //  Calculate covariance matrix of predicted residuals R = V + H*C*Ht = V + H*St, and its inverse. 
  //  (Call this Rmat instead of R to avoid confusion with track radius).
  for (i0 = 0; i0 < 2; i0++) {
    for (i1 = 0; i1 < 2; i1++) {
      pitchPSoverR = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        pitchPSoverR += H[i0 + (i2 << 1)] * St[i2 + (i1 << 2)];
      }

      Rmat[i0 + (i1 << 1)] = V[i0 + (i1 << 1)] + pitchPSoverR;
    }
  }

  if (std::abs(Rmat[1]) > std::abs(Rmat[0])) {
    pitchPSoverR = Rmat[0] / Rmat[1];
    absZ = 1.0 / (pitchPSoverR * Rmat[3] - Rmat[2]);
    RmatInv[0] = Rmat[3] / Rmat[1] * absZ;
    RmatInv[1] = -absZ;
    RmatInv[2] = -Rmat[2] / Rmat[1] * absZ;
    RmatInv[3] = pitchPSoverR * absZ;
  } else {
    pitchPSoverR = Rmat[1] / Rmat[0];
    absZ = 1.0 / (Rmat[3] - pitchPSoverR * Rmat[2]);
    RmatInv[0] = Rmat[3] / Rmat[0] * absZ;
    RmatInv[1] = -pitchPSoverR * absZ;
    RmatInv[2] = -Rmat[2] / Rmat[0] * absZ;
    RmatInv[3] = absZ;
  }

  //  Calculate Kalman gain matrix * determinant(R): K = S*R(inverse)
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 2; i1++) {
      K[i0 + (i1 << 2)] = 0.0;
      for (i2 = 0; i2 < 2; i2++) {
        K[i0 + (i1 << 2)] += St[i0 + (i2 << 2)] * RmatInv[i2 + (i1 << 1)];
      }
    }
  }

  //  Calculate hit residuals.
  for (i0 = 0; i0 < 2; i0++) {
    pitchPSoverR = 0.0;
    for (i1 = 0; i1 < 4; i1++) {
      pitchPSoverR += H[i0 + (i1 << 1)] * x[i1];
    }

    res[i0] = m[i0] - pitchPSoverR;
  }

  //  Calculate output helix params & their covariance matrix.
  for (i0 = 0; i0 < 4; i0++) {
    pitchPSoverR = 0.0;
    for (i1 = 0; i1 < 2; i1++) {
      pitchPSoverR += K[i0 + (i1 << 2)] * res[i1];
    }

    Rmat[i0] = x[i0] + pitchPSoverR;
  }

  for (i0 = 0; i0 < 2; i0++) {
    for (i1 = 0; i1 < 2; i1++) {
      V[i1 + (i0 << 1)] = Rmat[i1 + (i0 << 1)];
    }
  }

  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      pitchPSoverR = 0.0;
      for (i2 = 0; i2 < 2; i2++) {
        pitchPSoverR += K[i0 + (i2 << 2)] * S[i2 + (i1 << 1)];
      }

      C_new[i0 + (i1 << 2)] = C[i0 + (i1 << 2)] - pitchPSoverR;
    }
  }

  //  Calculate increase in chi2 from adding new stub: delta(chi2) = res(transpose) * R(inverse) * res 
  //  delta(chi2) = res(transpose) * R(inverse) * res
  //  dChi2 = res' * RmatInv * res;
  pitchPSoverR = stateIn->chiSquared + ((res[0] * res[0] * RmatInv[0] + res[1] *
    res[1] * RmatInv[3]) + 2.0 * (res[0] * res[1]) * RmatInv[2]);

  //  Truncate chi2 to avoid overflow.
  if (pitchPSoverR > 0.0) {
    pitchPSoverR = 0.0;
  }

  stateOut->chiSquared = pitchPSoverR;
  stateOut->inv2R = V[0];
  stateOut->phi0 = V[1];
  stateOut->tanL = V[2];
  stateOut->z0 = V[3];
  stateOut->cov_00 = C_new[0];
  stateOut->cov_11 = C_new[5];
  stateOut->cov_22 = C_new[10];
  stateOut->cov_33 = C_new[15];
  stateOut->cov_01 = C_new[4];
  stateOut->cov_23 = C_new[14];
}

//
// File trailer for KalmanUpdateHLS.cpp
//
// [EOF]
//
