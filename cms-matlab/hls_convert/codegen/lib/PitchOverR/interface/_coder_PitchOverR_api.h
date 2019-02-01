/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_PitchOverR_api.h
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 06-Jul-2018 18:00:43
 */

#ifndef _CODER_PITCHOVERR_API_H
#define _CODER_PITCHOVERR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_PitchOverR_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T PitchOverR(real_T pitch, real_T r);
extern void PitchOverR_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1]);
extern void PitchOverR_atexit(void);
extern void PitchOverR_initialize(void);
extern void PitchOverR_terminate(void);
extern void PitchOverR_xil_terminate(void);

#endif

/*
 * File trailer for _coder_PitchOverR_api.h
 *
 * [EOF]
 */
