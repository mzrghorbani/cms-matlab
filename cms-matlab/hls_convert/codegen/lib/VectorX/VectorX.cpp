//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: VectorX.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 19:39:42
//

// Include Files
#include "rt_nonfinite.h"
#include "VectorX.h"

// Function Definitions

//
// _0(inv2R), _1(phi0), _2(tanL), _3(z0)
// Arguments    : double inv2R
//                double phi0
//                double tanL
//                double z0
//                double x[4]
// Return Type  : void
//
void VectorX(double inv2R, double phi0, double tanL, double z0, double x[4])
{
  x[0] = inv2R;
  x[1] = phi0;
  x[2] = tanL;
  x[3] = z0;
}

//
// File trailer for VectorX.cpp
//
// [EOF]
//
