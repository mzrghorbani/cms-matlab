//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixR.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 20-Jun-2018 11:54:11
//

// Include Files
#include "rt_nonfinite.h"
#include "MatrixR.h"

// Function Definitions

//
// Arguments    : const double V[4]
//                const double H[8]
//                const double St[8]
//                double Rmat[4]
// Return Type  : void
//
void MatrixR(const double V[4], const double H[8], const double St[8], double
             Rmat[4])
{
  int i0;
  int i1;
  double d0;
  int i2;
  for (i0 = 0; i0 < 2; i0++) {
    for (i1 = 0; i1 < 2; i1++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 4; i2++) {
        d0 += H[i0 + (i2 << 1)] * St[i2 + (i1 << 2)];
      }

      Rmat[i0 + (i1 << 1)] = V[i0 + (i1 << 1)] + d0;
    }
  }
}

//
// File trailer for MatrixR.cpp
//
// [EOF]
//
