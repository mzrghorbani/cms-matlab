//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calcDeltaChi2_0.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 13-Aug-2018 18:47:08
//

// Include Files
#include "rt_nonfinite.h"
#include "calcDeltaChi2_0.h"

// Function Definitions

//
// Arguments    : const double res[2]
//                const double RmatInv[4]
// Return Type  : double
//
double calcDeltaChi2_0(const double res[2], const double RmatInv[4])
{
  double dChi2_0;
  int i0;
  double b_res[2];
  int i1;
  dChi2_0 = 0.0;
  for (i0 = 0; i0 < 2; i0++) {
    b_res[i0] = 0.0;
    for (i1 = 0; i1 < 2; i1++) {
      b_res[i0] += res[i1] * RmatInv[i1 + (i0 << 1)];
    }

    dChi2_0 += b_res[i0] * res[i0];
  }

  return dChi2_0;
}

//
// File trailer for calcDeltaChi2_0.cpp
//
// [EOF]
//
