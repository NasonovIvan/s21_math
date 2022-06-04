#include "s21_math.h"

long double s21_acos(double x) {
  long double acos = 0.;
  if (x == 1.) {
    return 0;
  } else if (x == -1.) {
    return S21_PI;
  } else if (x == 0) {
    return S21_PI / 2;
  }
  if (x == 0.7071067811865475244) {
    return S21_PI / 4;
  }
  if (x == -0.7071067811865475244) {
    return 3 * S21_PI / 4;
  }
  if (0. < x && x < 1.) {
    acos = s21_atan(s21_sqrt(1 - x * x) / x);
  } else if (-1. < x && x < 0.) {
    acos = S21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  } else {
    return S21_NAN;
  }
  return acos;
}
