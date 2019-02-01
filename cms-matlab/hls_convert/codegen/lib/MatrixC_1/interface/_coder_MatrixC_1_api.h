/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_MatrixC_1_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jun-2018 18:54:07
 */

#ifndef _CODER_MATRIXC_1_API_H
#define _CODER_MATRIXC_1_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_MatrixC_1_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void MatrixC_1(real_T C[16], real_T K[8], real_T S[8], real_T C_new[16]);
extern void MatrixC_1_api(const mxArray * const prhs[3], int32_T nlhs, const
  mxArray *plhs[1]);
extern void MatrixC_1_atexit(void);
extern void MatrixC_1_initialize(void);
extern void MatrixC_1_terminate(void);
extern void MatrixC_1_xil_terminate(void);

#endif

/*
 * File trailer for _coder_MatrixC_1_api.h
 *
 * [EOF]
 */
