#include "s21_math.h"

long double s21_fmax(double a, double b) {
  long double res = 1;
  if (a >= b) {
    res = a;
  } else {
    res = b;
  }
  return res;
}

long double s21_sqrt(double x) {
  if (is_nan(x)) {
    return S21_NAN;
  }
  long double left = 0;
  long double right = s21_fmax(1, x);
  long double mid;
  mid = (left + right) / 2;
  if (x < 0) {
    mid = S21_NAN;
  } else {
    while ((mid - left) > S21_EPS) {
      if (mid * mid > x)
        right = mid;
      else
        left = mid;
      mid = (left + right) / 2;
    }
  }
  return mid;
}
