#include "s21_math.h"

long double s21_factorial(int N) {
  if (N < 0) {
    return 0;
  }
  if (N == 0) {
    return 1;
  } else {
    return N * s21_factorial(N - 1);
  }
}
