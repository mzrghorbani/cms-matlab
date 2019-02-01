/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_MatrixK_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jun-2018 18:46:45
 */

#ifndef _CODER_MATRIXK_API_H
#define _CODER_MATRIXK_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_MatrixK_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void MatrixK(real_T St[8], real_T RmatInv[4], real_T K[8]);
extern void MatrixK_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void MatrixK_atexit(void);
extern void MatrixK_initialize(void);
extern void MatrixK_terminate(void);
extern void MatrixK_xil_terminate(void);

#endif

/*
 * File trailer for _coder_MatrixK_api.h
 *
 * [EOF]
 */
