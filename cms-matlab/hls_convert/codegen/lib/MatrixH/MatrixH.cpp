//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixH.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 20-Jun-2018 11:39:59
//

// Include Files
#include "rt_nonfinite.h"
#include "MatrixH.h"

// Function Definitions

//
// Arguments    : double r
//                double H[8]
// Return Type  : void
//
void MatrixH(double r, double H[8])
{
  H[0] = -r;
  H[2] = 1.0;
  H[4] = 0.0;
  H[6] = 0.0;
  H[1] = 0.0;
  H[3] = 0.0;
  H[5] = r;
  H[7] = 1.0;
}

//
// File trailer for MatrixH.cpp
//
// [EOF]
//
