//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: calcDeltaChi2.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 13-Aug-2018 17:17:36
//

// Include Files
#include "rt_nonfinite.h"
#include "calcDeltaChi2.h"

// Function Definitions

//
// delta(chi2) = res(transpose) * R(inverse) * res
//  dChi2 = res' * RmatInv * res;
// Arguments    : const double res[2]
//                const double RmatInv[4]
// Return Type  : double
//
double calcDeltaChi2(const double res[2], const double RmatInv[4])
{
  return (res[0] * res[0] * RmatInv[0] + res[1] * res[1] * RmatInv[3]) + 2.0 *
    (res[0] * res[1]) * RmatInv[2];
}

//
// File trailer for calcDeltaChi2.cpp
//
// [EOF]
//
