//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixK.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 18:46:45
//

// Include Files
#include "rt_nonfinite.h"
#include "MatrixK.h"

// Function Definitions

//
// Arguments    : const double St[8]
//                const double RmatInv[4]
//                double K[8]
// Return Type  : void
//
void MatrixK(const double St[8], const double RmatInv[4], double K[8])
{
  int i0;
  int i1;
  int i2;
  for (i0 = 0; i0 < 4; i0++) {
    for (i1 = 0; i1 < 2; i1++) {
      K[i0 + (i1 << 2)] = 0.0;
      for (i2 = 0; i2 < 2; i2++) {
        K[i0 + (i1 << 2)] += St[i0 + (i2 << 2)] * RmatInv[i2 + (i1 << 1)];
      }
    }
  }
}

//
// File trailer for MatrixK.cpp
//
// [EOF]
//
