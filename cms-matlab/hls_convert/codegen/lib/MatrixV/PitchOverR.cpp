//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: PitchOverR.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 18:27:26
//

// Include Files
#include <cmath>
#include <string.h>
#include "rt_nonfinite.h"
#include "MatrixV.h"
#include "PitchOverR.h"
#include "bitsll.h"

// Function Declarations
static double rt_roundd_snf(double u);

// Function Definitions

//
// Arguments    : double u
// Return Type  : double
//
static double rt_roundd_snf(double u)
{
  double y;
  if (std::abs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = std::floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = std::ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

//
// Arguments    : double pitch
//                double r
// Return Type  : double
//
double PitchOverR(double pitch, double r)
{
  double get[512];
  int n;
  memset(&get[0], 0, sizeof(double) << 9);
  for (n = 0; n < 509; n++) {
    //  Don't bother initializing first two, as would overflow bit range.
    get[n + 2] = pitch / (bitsll(3.0 + (double)n) + 0.5 * bitsll(1.0));

    //  Round to nearest half integer
  }

  return get[(int)rt_roundd_snf(r / 4.0) - 1];
}

//
// File trailer for PitchOverR.cpp
//
// [EOF]
//
