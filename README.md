# s21_math
## Introduction

In this project I developed my own version of the standard math.h library in the C programming language. This library implements basic mathematical operations, which are then used in various algorithms.

## Information

C mathematical operations are a group of functions in the standard library of the C programming language implementing basic mathematical functions. All functions use floating-point numbers in one manner or another. Different C standards provide different, albeit backwards-compatible, sets of functions. Any functions that operate on angles use radians as the unit of angle.

### Overview of some "math.h" functions

| No. | Function | Description |
| --- | -------- | ----------- |
| 1 | `int abs(int x)` | computes absolute value of an integer value |
| 2 | `long double acos(double x)` | computes arc cosine |
| 3 | `long double asin(double x)` | computes arc sine |
| 4 | `long double atan(double x)` | computes arc tangent |
| 5 | `long double ceil(double x)` | returns the nearest integer not less than the given value |
| 6 | `long double cos(double x)` | computes cosine |
| 7 | `long double exp(double x)` | returns e raised to the given power |
| 8 | `long double fabs(double x)` | computes absolute value of a floating-point value |
| 9 | `long double floor(double x)` | returns the nearest integer not greater than the given value |
| 10 | `long double fmod(double x, double y)` | remainder of the floating-point division operation |
| 11 | `long double log(double x)` | computes natural logarithm |
| 12 | `long double pow(double base, double exp)` | raises a number to the given power |
| 13 | `long double sin(double x)` | computes sine |
| 14 | `long double sqrt(double x)` | computes square root |
| 15 | `long double tan(double x)` | computes tangent |  

## Implementing the math.h library functions

- The library developed in C language of C11 standard using gcc compiler. In project the POSIX.1-2017 standard is used
- Unit-tests check the results of implementation by comparing them with the implementation of the standard math.h library
- Unit tests cover at least 80% of each function (check using gcov)
- The total verifiable accuracy is 16 significant digits
- Verifiable accuracy of the fractional part is up to 6 decimal places.

## Start program

Use ```git clone``` to copy the project.
Then enter the following command in the C4 folder:

To create a library, test its functions and get a [gcovr](https://gcovr.com/en/stable/) html-report on the coverage of functions with tests:
```sh
make
```

For building the library *s21_math.a*:
```sh
make s21_math.a
```

For testing the functions:
```sh
make test
```

If you want to check the code using *cppcheck*, *leaks* or *valgrind*, use the command:
```sh
make check
```

>The commands assume that you have a gcc compiler and some utilities installed!
