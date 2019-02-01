/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_VectorM_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 20-Jun-2018 11:20:32
 */

#ifndef _CODER_VECTORM_API_H
#define _CODER_VECTORM_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_VectorM_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void VectorM(real_T phiS, real_T z, real_T m[2]);
extern void VectorM_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void VectorM_atexit(void);
extern void VectorM_initialize(void);
extern void VectorM_terminate(void);
extern void VectorM_xil_terminate(void);

#endif

/*
 * File trailer for _coder_VectorM_api.h
 *
 * [EOF]
 */
