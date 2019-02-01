//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: VectorX_1.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 18:51:55
//

// Include Files
#include "rt_nonfinite.h"
#include "VectorX_1.h"

// Function Definitions

//
// Arguments    : const double x[4]
//                const double K[8]
//                const double res[2]
//                double x_new[4]
// Return Type  : void
//
void VectorX_1(const double x[4], const double K[8], const double res[2], double
               x_new[4])
{
  int i0;
  double d0;
  int i1;
  for (i0 = 0; i0 < 4; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 2; i1++) {
      d0 += K[i0 + (i1 << 2)] * res[i1];
    }

    x_new[i0] = x[i0] + d0;
  }
}

//
// File trailer for VectorX_1.cpp
//
// [EOF]
//
