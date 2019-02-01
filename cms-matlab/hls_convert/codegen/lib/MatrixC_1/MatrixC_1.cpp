//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixC_1.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 18:54:07
//

// Include Files
#include "rt_nonfinite.h"
#include "MatrixC_1.h"

// Function Definitions

//
// Arguments    : const double C[16]
//                const double K[8]
//                const double S[8]
//                double C_new[16]
// Return Type  : void
//
void MatrixC_1(const double C[16], const double K[8], const double S[8], double
               C_new[16])
{
  int i0;
  int i1;
  double d0;
  int i2;
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 4; i1++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 2; i2++) {
        d0 += K[i0 + (i2 << 2)] * S[i2 + (i1 << 1)];
      }

      C_new[i0 + (i1 << 2)] = C[i0 + (i1 << 2)] - d0;
    }
  }
}

//
// File trailer for MatrixC_1.cpp
//
// [EOF]
//
