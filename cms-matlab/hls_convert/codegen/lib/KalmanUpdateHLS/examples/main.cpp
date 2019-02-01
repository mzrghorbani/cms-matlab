//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: main.cpp
//
// MATLAB Coder version            : 4.0
// C/C++ source code generated on  : 19-Jun-2018 19:22:55
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
#include "KalmanUpdateHLS.h"
#include "main.h"
#include "KalmanUpdateHLS_terminate.h"
#include "KalmanUpdateHLS_initialize.h"

// Function Declarations
static short argInit_int16_T();
static double argInit_real_T();
static struct0_T argInit_struct0_T();
static void argInit_struct1_T(struct1_T *result);
static void main_KalmanUpdateHLS();

// Function Definitions

//
// Arguments    : void
// Return Type  : short
//
static short argInit_int16_T()
{
  return 0;
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
// Return Type  : struct0_T
//
static struct0_T argInit_struct0_T()
{
  struct0_T result;

  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result.r = argInit_real_T();
  result.z = argInit_real_T();
  result.phiS = argInit_real_T();
  return result;
}

//
// Arguments    : struct1_T *result
// Return Type  : void
//
static void argInit_struct1_T(struct1_T *result)
{
  // Set the value of each structure field.
  // Change this value to the value that the application requires.
  result->cBin = argInit_int16_T();
  result->mBin = argInit_int16_T();
  result->chiSquared = argInit_real_T();
  result->inv2R = argInit_real_T();
  result->phi0 = argInit_real_T();
  result->tanL = argInit_real_T();
  result->z0 = argInit_real_T();
  result->cov_00 = argInit_real_T();
  result->cov_11 = argInit_real_T();
  result->cov_22 = argInit_real_T();
  result->cov_33 = argInit_real_T();
  result->cov_01 = argInit_real_T();
  result->cov_23 = argInit_real_T();
}

//
// Arguments    : void
// Return Type  : void
//
static void main_KalmanUpdateHLS()
{
  struct1_T r0;
  struct0_T r1;
  struct1_T stateOut;

  // Initialize function 'KalmanUpdateHLS' input arguments.
  // Initialize function input argument 'stub'.
  // Initialize function input argument 'stateIn'.
  // Call the entry-point 'KalmanUpdateHLS'.
  argInit_struct1_T(&r0);
  r1 = argInit_struct0_T();
  KalmanUpdateHLS(&r1, &r0, &stateOut);
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
  KalmanUpdateHLS_initialize();

  // Invoke the entry-point functions.
  // You can call entry-point functions multiple times.
  main_KalmanUpdateHLS();

  // Terminate the application.
  // You do not need to do this more than one time.
  KalmanUpdateHLS_terminate();
  return 0;
}

//
// File trailer for main.cpp
//
// [EOF]
//
