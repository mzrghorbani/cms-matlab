//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: MatrixC.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 18:35:08
//

// Include Files
#include "rt_nonfinite.h"
#include "MatrixC.h"

// Function Definitions

//
// Arguments    : double c00
//                double c11
//                double c22
//                double c33
//                double c01
//                double c23
//                double C[16]
// Return Type  : void
//
void MatrixC(double c00, double c11, double c22, double c33, double c01, double
             c23, double C[16])
{
  C[0] = c00;
  C[5] = c11;
  C[10] = c22;
  C[15] = c33;
  C[4] = c01;
  C[14] = c23;
  C[8] = 0.0;
  C[12] = 0.0;
  C[9] = 0.0;
  C[13] = 0.0;
  C[1] = c01;
  C[11] = c23;
  C[2] = 0.0;
  C[3] = 0.0;
  C[6] = 0.0;
  C[7] = 0.0;
}

//
// File trailer for MatrixC.cpp
//
// [EOF]
//
