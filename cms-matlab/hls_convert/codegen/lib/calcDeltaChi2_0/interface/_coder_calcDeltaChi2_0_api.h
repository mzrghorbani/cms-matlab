/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_calcDeltaChi2_0_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 13-Aug-2018 18:47:08
 */

#ifndef _CODER_CALCDELTACHI2_0_API_H
#define _CODER_CALCDELTACHI2_0_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_calcDeltaChi2_0_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T calcDeltaChi2_0(real_T res[2], real_T RmatInv[4]);
extern void calcDeltaChi2_0_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[1]);
extern void calcDeltaChi2_0_atexit(void);
extern void calcDeltaChi2_0_initialize(void);
extern void calcDeltaChi2_0_terminate(void);
extern void calcDeltaChi2_0_xil_terminate(void);

#endif

/*
 * File trailer for _coder_calcDeltaChi2_0_api.h
 *
 * [EOF]
 */
