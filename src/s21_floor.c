#include "s21_math.h"

long double s21_floor(double x) {
  if (!is_fin(x)) {
    return x;
  }
  long double floor_x = (long long int)x;
  if (s21_fabs(x - floor_x) > 0. && s21_fabs(x) > 0.) {
    if (x < 0.) {
      floor_x -= 1;
    }
  }
  return floor_x;
}
