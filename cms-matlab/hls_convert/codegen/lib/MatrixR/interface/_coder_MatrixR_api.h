/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_MatrixR_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jun-2018 11:54:11
 */

#ifndef _CODER_MATRIXR_API_H
#define _CODER_MATRIXR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_MatrixR_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void MatrixR(real_T V[4], real_T H[8], real_T St[8], real_T Rmat[4]);
extern void MatrixR_api(const mxArray * const prhs[3], int32_T nlhs, const
  mxArray *plhs[1]);
extern void MatrixR_atexit(void);
extern void MatrixR_initialize(void);
extern void MatrixR_terminate(void);
extern void MatrixR_xil_terminate(void);

#endif

/*
 * File trailer for _coder_MatrixR_api.h
 *
 * [EOF]
 */
