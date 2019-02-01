/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_MatrixS_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 22-Jun-2018 20:16:40
 */

#ifndef _CODER_MATRIXS_API_H
#define _CODER_MATRIXS_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_MatrixS_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void MatrixS(real_T H[8], real_T C[16], real_T S[8]);
extern void MatrixS_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void MatrixS_atexit(void);
extern void MatrixS_initialize(void);
extern void MatrixS_terminate(void);
extern void MatrixS_xil_terminate(void);

#endif

/*
 * File trailer for _coder_MatrixS_api.h
 *
 * [EOF]
 */
