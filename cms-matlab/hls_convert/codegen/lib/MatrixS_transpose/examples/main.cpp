//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 20-Jun-2018 11:52:25
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
#include "MatrixS_transpose.h"
#include "main.h"
#include "MatrixS_transpose_terminate.h"
#include "MatrixS_transpose_initialize.h"

// Function Declarations
static void argInit_2x4_real_T(double result[8]);
static double argInit_real_T();
static void main_MatrixS_transpose();

// Function Definitions

//
// Arguments    : double result[8]
// Return Type  : void
//
static void argInit_2x4_real_T(double result[8])
{
  int idx0;
  int idx1;

  // Loop over the array to initialize each element.
  for (idx0 = 0; idx0 < 2; idx0++) {
    for (idx1 = 0; idx1 < 4; idx1++) {
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
static void main_MatrixS_transpose()
{
  double dv0[8];
  double St[8];

  // Initialize function 'MatrixS_transpose' input arguments.
  // Initialize function input argument 'S'.
  // Call the entry-point 'MatrixS_transpose'.
  argInit_2x4_real_T(dv0);
  MatrixS_transpose(dv0, St);
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
  MatrixS_transpose_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_MatrixS_transpose();

  // Terminate the application.
  // You do not need to do this more than one time.
  MatrixS_transpose_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
