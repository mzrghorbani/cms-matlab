//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: bitsll.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 06-Jul-2018 18:00:43
//

// Include Files
#include <cmath>
#include "rt_nonfinite.h"
#include "PitchOverR.h"
#include "bitsll.h"

// Function Definitions

//
// Arguments    : double u
// Return Type  : double
//
double bitsll(double u)
{
  return std::ldexp(u, 2);
}

//
// File trailer for bitsll.cpp
//
// [EOF]
//
