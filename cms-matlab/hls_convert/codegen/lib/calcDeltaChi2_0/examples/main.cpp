//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 13-Aug-2018 18:47:08
//

//***********************************************************************
// This automatically generated example C main file shows how to call
// entry-point functions that MATLAB Coder generated. You must customize
// this file for your application. Do not modify this file directly.
// Instead, make a copy of this file, modify it, and integrate it into
// your development environment.
//
// This file initializes entry-point function arguments to a default
// size and value before calling the entry-point functions. It does
// not store or use any values returned from the entry-point functions.
// If necessary, it does pre-allocate memory for returned values.
// You can use this file as a starting point for a main function that
// you can deploy in your application.
//
// After you copy the file, and before you deploy it, you must make the
// following changes:
// * For variable-size function arguments, change the example sizes to
// the sizes that your application requires.
// * Change the example values of function arguments to the values that
// your application requires.
// * If the entry-point functions return values, store these values or
// otherwise use them as required by your application.
//
//***********************************************************************
// Include Files
#include "rt_nonfinite.h"
#include "calcDeltaChi2_0.h"
#include "main.h"
#include "calcDeltaChi2_0_terminate.h"
#include "calcDeltaChi2_0_initialize.h"

// Function Declarations
static void argInit_2x1_real_T(double result[2]);
static void argInit_2x2_real_T(double result[4]);
static double argInit_real_T();
static void main_calcDeltaChi2_0();

// Function Definitions

//
// Arguments    : double result[2]
// Return Type  : void
//
static void argInit_2x1_real_T(double result[2])
{
  int idx0;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 2; idx0++) {
    // Set the value of the array element.
    // Change this value to the value that the application requires.
    result[idx0] = argInit_real_T();
  }
}

//
// Arguments    : double result[4]
// Return Type  : void
//
static void argInit_2x2_real_T(double result[4])
{
  int idx0;
  int idx1;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < 2; idx1++) {
      // Set the value of the array element.
      // Change this value to the value that the application requires.
      result[idx0 + (idx1 << 1)] = argInit_real_T();
    }
  }
}

//
// Arguments    : void
// Return Type  : double
//
static double argInit_real_T()
{
  return 0.0;
}

//
// Arguments    : void
// Return Type  : void
//
static void main_calcDeltaChi2_0()
{
  double dv0[2];
  double dv1[4];
  double dChi2_0;

  // Initialize function 'calcDeltaChi2_0' input arguments.
  // Initialize function input argument 'res'.
  // Initialize function input argument 'RmatInv'.
  // Call the entry-point 'calcDeltaChi2_0'.
  argInit_2x1_real_T(dv0);
  argInit_2x2_real_T(dv1);
  dChi2_0 = calcDeltaChi2_0(dv0, dv1);
}

//
// Arguments    : int argc
//                const char * const argv[]
// Return Type  : int
//
int main(int, const char * const [])
{
  // Initialize the application.
  // You do not need to do this more than one time.
  calcDeltaChi2_0_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_calcDeltaChi2_0();

  // Terminate the application.
  // You do not need to do this more than one time.
  calcDeltaChi2_0_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
