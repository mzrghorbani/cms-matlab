//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: VectorRes.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 18:49:24
//

// Include Files
#include "rt_nonfinite.h"
#include "VectorRes.h"

// Function Definitions

//
// Arguments    : const double m[2]
//                const double H[8]
//                const double x[4]
//                double res[2]
// Return Type  : void
//
void VectorRes(const double m[2], const double H[8], const double x[4], double
               res[2])
{
  int i0;
  double d0;
  int i1;
  for (i0 = 0; i0 < 2; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 4; i1++) {
      d0 += H[i0 + (i1 << 1)] * x[i1];
    }

    res[i0] = m[i0] - d0;
  }
}

//
// File trailer for VectorRes.cpp
//
// [EOF]
//
