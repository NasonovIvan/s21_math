#include "s21_math.h"

long double s21_tan(double x) {
  if (x == S21_PI / 2) {
    return 16331239353195370L;
  } else if (x == -S21_PI / 2) {
    return -16331239353195370L;
  }
  if (x == 0) {
    return 0;
  }
  return s21_sin(x) / s21_cos(x);
}
