/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_MatrixInverseR_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jun-2018 18:43:59
 */

#ifndef _CODER_MATRIXINVERSER_API_H
#define _CODER_MATRIXINVERSER_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_MatrixInverseR_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void MatrixInverseR(real_T Rmat[4], real_T RmatInv[4]);
extern void MatrixInverseR_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void MatrixInverseR_atexit(void);
extern void MatrixInverseR_initialize(void);
extern void MatrixInverseR_terminate(void);
extern void MatrixInverseR_xil_terminate(void);

#endif

/*
 * File trailer for _coder_MatrixInverseR_api.h
 *
 * [EOF]
 */
