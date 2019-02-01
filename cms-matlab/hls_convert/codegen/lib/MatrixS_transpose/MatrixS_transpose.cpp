//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixS_transpose.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 20-Jun-2018 11:52:25
//

// Include Files
#include "rt_nonfinite.h"
#include "MatrixS_transpose.h"

// Function Definitions

//
// Arguments    : const double S[8]
//                double St[8]
// Return Type  : void
//
void MatrixS_transpose(const double S[8], double St[8])
{
  int i0;
  int i1;
  for (i0 = 0; i0 < 2; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      St[i1 + (i0 << 2)] = S[i0 + (i1 << 1)];
    }
  }
}

//
// File trailer for MatrixS_transpose.cpp
//
// [EOF]
//
