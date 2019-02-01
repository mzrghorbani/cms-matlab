//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixS.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 22-Jun-2018 20:16:40
//

// Include Files
#include "rt_nonfinite.h"
#include "MatrixS.h"

// Function Definitions

//
// Arguments    : const double H[8]
//                const double C[16]
//                double S[8]
// Return Type  : void
//
void MatrixS(const double H[8], const double C[16], double S[8])
{
  int i0;
  int i1;
  int i2;
  for (i0 = 0; i0 < 2; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      S[i0 + (i1 << 1)] = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        S[i0 + (i1 << 1)] += H[i0 + (i2 << 1)] * C[i2 + (i1 << 2)];
      }
    }
  }
}

//
// File trailer for MatrixS.cpp
//
// [EOF]
//
