//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixInverseR.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 18:43:59
//

// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "MatrixInverseR.h"

// Function Definitions

//
// Arguments    : const double Rmat[4]
//                double RmatInv[4]
// Return Type  : void
//
void MatrixInverseR(const double Rmat[4], double RmatInv[4])
{
  double r;
  double t;
  if (std::abs(Rmat[1]) > std::abs(Rmat[0])) {
    r = Rmat[0] / Rmat[1];
    t = 1.0 / (r * Rmat[3] - Rmat[2]);
    RmatInv[0] = Rmat[3] / Rmat[1] * t;
    RmatInv[1] = -t;
    RmatInv[2] = -Rmat[2] / Rmat[1] * t;
    RmatInv[3] = r * t;
  } else {
    r = Rmat[1] / Rmat[0];
    t = 1.0 / (Rmat[3] - r * Rmat[2]);
    RmatInv[0] = Rmat[3] / Rmat[0] * t;
    RmatInv[1] = -r * t;
    RmatInv[2] = -Rmat[2] / Rmat[0] * t;
    RmatInv[3] = t;
  }
}

//
// File trailer for MatrixInverseR.cpp
//
// [EOF]
//
