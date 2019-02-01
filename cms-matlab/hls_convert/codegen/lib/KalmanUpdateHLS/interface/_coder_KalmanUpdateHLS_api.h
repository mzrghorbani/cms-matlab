/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_KalmanUpdateHLS_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jun-2018 19:22:55
 */

#ifndef _CODER_KALMANUPDATEHLS_API_H
#define _CODER_KALMANUPDATEHLS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_KalmanUpdateHLS_api.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T

typedef struct {
  real_T r;
  real_T z;
  real_T phiS;
} struct0_T;

#endif                                 /*typedef_struct0_T*/

#ifndef typedef_struct1_T
#define typedef_struct1_T

typedef struct {
  int16_T cBin;
  int16_T mBin;
  real_T chiSquared;
  real_T inv2R;
  real_T phi0;
  real_T tanL;
  real_T z0;
  real_T cov_00;
  real_T cov_11;
  real_T cov_22;
  real_T cov_33;
  real_T cov_01;
  real_T cov_23;
} struct1_T;

#endif                                 /*typedef_struct1_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void KalmanUpdateHLS(struct0_T *stub, struct1_T *stateIn, struct1_T
  *stateOut);
extern void KalmanUpdateHLS_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[1]);
extern void KalmanUpdateHLS_atexit(void);
extern void KalmanUpdateHLS_initialize(void);
extern void KalmanUpdateHLS_terminate(void);
extern void KalmanUpdateHLS_xil_terminate(void);

#endif

/*
 * File trailer for _coder_KalmanUpdateHLS_api.h
 *
 * [EOF]
 */
