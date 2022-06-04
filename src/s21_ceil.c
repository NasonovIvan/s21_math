#include "s21_math.h"

long double s21_ceil(double x) {
  if (!is_fin(x)) {
    return x;
  }
  long double ceil_x = (long long int)x;
  if (s21_fabs(x) > 0. && x != ceil_x) {
    if (x != DBL_MAX) {
      if (x > 0.) {
        ceil_x += 1;
      }
    } else {
      return DBL_MAX;
    }
  }
  return ceil_x;
}
