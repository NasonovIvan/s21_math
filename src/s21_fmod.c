#include "s21_math.h"

long double s21_fmod(double x, double y) {
  if (!is_fin(x) || is_nan(y)) {
    return S21_NAN;
  }
  if (is_inf(x) && is_inf(y)) {
    return S21_NAN;
  }
  if (is_inf(y)) {
    return x;
  }
  if (s21_fabs(y) < 1e-7) {
    return S21_NAN;
  }
  if (s21_fabs(x) < 1e-7) {
    return 0;
  }
  long long int mod = 0;
  mod = x / y;
  long double res = (long double)x - mod * (long double)y;
  return res;
}
