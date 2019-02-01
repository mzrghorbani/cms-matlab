/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: _coder_KalmanUpdateHLS_api.c
 *
 * MATLAB Coder version            : 4.0
 * C/C++ source code generated on  : 19-Jun-2018 19:22:55
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_KalmanUpdateHLS_api.h"
#include "_coder_KalmanUpdateHLS_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131466U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "KalmanUpdateHLS",                   /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static struct0_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId);
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *stateIn,
  const char_T *identifier, struct1_T *y);
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y);
static struct0_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *stub,
  const char_T *identifier);
static const mxArray *emlrt_marshallOut(const struct1_T *u);
static int16_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId);
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId);
static int16_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId);

/* Function Definitions */

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : struct0_T
 */
static struct0_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
  const emlrtMsgIdentifier *parentId)
{
  struct0_T y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[3] = { "r", "z", "phiS" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 3, fieldNames, 0U, (int32_T *)&dims);
  thisId.fIdentifier = "r";
  y.r = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0, "r")),
    &thisId);
  thisId.fIdentifier = "z";
  y.z = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1, "z")),
    &thisId);
  thisId.fIdentifier = "phiS";
  y.phiS = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 2,
    "phiS")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = g_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *stateIn
 *                const char_T *identifier
 *                struct1_T *y
 * Return Type  : void
 */
static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *stateIn,
  const char_T *identifier, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  e_emlrt_marshallIn(sp, emlrtAlias(stateIn), &thisId, y);
  emlrtDestroyArray(&stateIn);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 *                struct1_T *y
 * Return Type  : void
 */
static void e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId, struct1_T *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[13] = { "cBin", "mBin", "chiSquared", "inv2R",
    "phi0", "tanL", "z0", "cov_00", "cov_11", "cov_22", "cov_33", "cov_01",
    "cov_23" };

  static const int32_T dims = 0;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b(sp, parentId, u, 13, fieldNames, 0U, (int32_T *)&dims);
  thisId.fIdentifier = "cBin";
  y->cBin = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 0,
    "cBin")), &thisId);
  thisId.fIdentifier = "mBin";
  y->mBin = f_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 1,
    "mBin")), &thisId);
  thisId.fIdentifier = "chiSquared";
  y->chiSquared = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0,
    2, "chiSquared")), &thisId);
  thisId.fIdentifier = "inv2R";
  y->inv2R = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 3,
    "inv2R")), &thisId);
  thisId.fIdentifier = "phi0";
  y->phi0 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 4,
    "phi0")), &thisId);
  thisId.fIdentifier = "tanL";
  y->tanL = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 5,
    "tanL")), &thisId);
  thisId.fIdentifier = "z0";
  y->z0 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 6,
    "z0")), &thisId);
  thisId.fIdentifier = "cov_00";
  y->cov_00 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 7,
    "cov_00")), &thisId);
  thisId.fIdentifier = "cov_11";
  y->cov_11 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 8,
    "cov_11")), &thisId);
  thisId.fIdentifier = "cov_22";
  y->cov_22 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 9,
    "cov_22")), &thisId);
  thisId.fIdentifier = "cov_33";
  y->cov_33 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 10,
    "cov_33")), &thisId);
  thisId.fIdentifier = "cov_01";
  y->cov_01 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 11,
    "cov_01")), &thisId);
  thisId.fIdentifier = "cov_23";
  y->cov_23 = c_emlrt_marshallIn(sp, emlrtAlias(emlrtGetFieldR2017b(sp, u, 0, 12,
    "cov_23")), &thisId);
  emlrtDestroyArray(&u);
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *stub
 *                const char_T *identifier
 * Return Type  : struct0_T
 */
static struct0_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *stub,
  const char_T *identifier)
{
  struct0_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(stub), &thisId);
  emlrtDestroyArray(&stub);
  return y;
}

/*
 * Arguments    : const struct1_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const struct1_T *u)
{
  const mxArray *y;
  static const char * sv0[13] = { "cBin", "mBin", "chiSquared", "inv2R", "phi0",
    "tanL", "z0", "cov_00", "cov_11", "cov_22", "cov_33", "cov_01", "cov_23" };

  const mxArray *b_y;
  const mxArray *m0;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 13, *(const char * (*)[13])&sv0
    [0]));
  b_y = NULL;
  m0 = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
  *(int16_T *)emlrtMxGetData(m0) = u->cBin;
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "cBin", b_y, 0);
  b_y = NULL;
  m0 = emlrtCreateNumericMatrix(1, 1, mxINT16_CLASS, mxREAL);
  *(int16_T *)emlrtMxGetData(m0) = u->mBin;
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "mBin", b_y, 1);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->chiSquared);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "chiSquared", b_y, 2);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->inv2R);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "inv2R", b_y, 3);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->phi0);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "phi0", b_y, 4);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->tanL);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "tanL", b_y, 5);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->z0);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "z0", b_y, 6);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->cov_00);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "cov_00", b_y, 7);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->cov_11);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "cov_11", b_y, 8);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->cov_22);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "cov_22", b_y, 9);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->cov_33);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "cov_33", b_y, 10);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->cov_01);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "cov_01", b_y, 11);
  b_y = NULL;
  m0 = emlrtCreateDoubleScalar(u->cov_23);
  emlrtAssign(&b_y, m0);
  emlrtSetFieldR2017b(y, 0, "cov_23", b_y, 12);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : int16_T
 */
static int16_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId)
{
  int16_T y;
  y = h_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src, const
  emlrtMsgIdentifier *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "double",
    false, 0U, (int32_T *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : int16_T
 */
static int16_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId)
{
  int16_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(sp, (const emlrtMsgIdentifier *)msgId, src, "int16",
    false, 0U, (int32_T *)&dims);
  ret = *(int16_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[2]
 *                int32_T nlhs
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void KalmanUpdateHLS_api(const mxArray * const prhs[2], int32_T nlhs, const
  mxArray *plhs[1])
{
  struct0_T stub;
  struct1_T stateIn;
  struct1_T stateOut;
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  (void)nlhs;
  st.tls = emlrtRootTLSGlobal;

  /* Marshall function inputs */
  stub = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "stub");
  d_emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "stateIn", &stateIn);

  /* Invoke the target function */
  KalmanUpdateHLS(&stub, &stateIn, &stateOut);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(&stateOut);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void KalmanUpdateHLS_atexit(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  KalmanUpdateHLS_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void KalmanUpdateHLS_initialize(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void KalmanUpdateHLS_terminate(void)
{
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_KalmanUpdateHLS_api.c
 *
 * [EOF]
 */
