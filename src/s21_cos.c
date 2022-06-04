#include "s21_math.h"

long double s21_cos(double x) {
  long double sum_cos = 0;
  if (x == S21_NAN || x == -S21_INF || x == S21_INF) {
    return S21_NAN;
  }
  for (; x < -2 * S21_PI || 2 * S21_PI < x;) {
    if (x > 2 * S21_PI) {
      x -= 2 * S21_PI;
    } else {
      x += 2 * S21_PI;
    }
  }
  if (x < 0) {
    x = -x;
  }
  for (register int i = 0; i < 500; i++) {
    sum_cos += s21_pow(-1, i) * s21_pow(x, 2 * i) / s21_factorial(2 * i);
  }
  return sum_cos;
}
