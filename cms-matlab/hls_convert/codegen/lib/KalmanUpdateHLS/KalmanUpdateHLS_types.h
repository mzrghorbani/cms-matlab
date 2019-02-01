//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: KalmanUpdateHLS_types.h
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 19:22:55
//
#ifndef KALMANUPDATEHLS_TYPES_H
#define KALMANUPDATEHLS_TYPES_H

// Include Files
#include "rtwtypes.h"

// Type Definitions
typedef struct {
  double r;
  double z;
  double phiS;
} struct0_T;

typedef struct {
  short cBin;
  short mBin;
  double chiSquared;
  double inv2R;
  double phi0;
  double tanL;
  double z0;
  double cov_00;
  double cov_11;
  double cov_22;
  double cov_33;
  double cov_01;
  double cov_23;
} struct1_T;

#endif

//
// File trailer for KalmanUpdateHLS_types.h
//
// [EOF]
//
