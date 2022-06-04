#include "s21_math.h"

long long int s21_abs_long_int(long long int x) { return x > 0 ? x : -x; }

long double s21_pow_helper(double base, double exp) {
  int base_is_nan = is_nan(base);
  int base_is_fin = is_fin(base);
  int exp_is_nan = is_nan(exp);
  int exp_is_fin = is_fin(exp);
  int exp_min = s21_fabs(exp - s21_floor(exp)) <= S21_EPS;

  // pow(+0, exp), where exp is a negative odd integer, returns +∞ and raises
  if (base_is_fin && !base_is_nan && base > 0 && base <= S21_EPS && exp_min &&
      ((int)exp) < 0 && ((int)exp) % 2) {
    return S21_INF;
  }

  // pow(-0, exp), where exp is a negative odd integer, returns -∞ and raises
  if (base_is_fin && !base_is_nan && base > 0 && base <= S21_EPS && exp_min &&
      ((int)exp) < 0 && ((int)exp) % 2) {
    return -S21_INF;
  }

  // pow(±0, exp), where exp is negative, finite, and is an even integer or a
  //  non-integer, returns +∞ and raises FE_DIVBYZERO
  if (base_is_fin && !base_is_nan && s21_fabs(base) < S21_EPS && exp_is_fin &&
      ((exp_min && !(((int)exp) % 2)) || !exp_min)) {
    if (base == 0 && exp == 0) {
      return 1;
    }
    if (base == 0 && exp > 0) {
      return 0;
    }
    return S21_INF;
  }

  // pow(±0, -∞) returns +∞ and may raise FE_DIVBYZERO
  if (base_is_fin && !base_is_nan && s21_fabs(base) < S21_EPS && !exp_is_nan &&
      !exp_is_fin && exp < 0) {
    return S21_INF;
  }

  // pow(+0, exp), where exp is a positive odd integer, returns +0
  if (base_is_fin && !base_is_nan && base > 0 && base <= S21_EPS && exp_min &&
      ((int)exp) % 2) {
    return +0;
  }

  // pow(-0, exp), where exp is a positive odd integer, returns -0
  if (base_is_fin && !base_is_nan && base < 0 && base >= -S21_EPS && exp_min &&
      ((int)exp) % 2) {
    return -0;
  }

  // pow(-0, exp), where exp is a positive odd integer, returns -0
  if (base_is_fin && !base_is_nan && base < 0 && base >= -S21_EPS && exp_min &&
      ((int)exp) % 2) {
    return -0;
  }

  // pow(±0, exp), where exp is positive non-integer or a positive even
  //  integer, returns +0
  if (base_is_fin && !base_is_nan && s21_fabs(base) < S21_EPS &&
      ((!exp_min && s21_fabs(exp) > S21_EPS) ||
       (exp_min && !(((int)exp) % 2)))) {
    return +0;
  }

  // pow(-1, ±∞) returns 1
  if (base_is_fin && !base_is_nan && s21_fabs(base + 1) < S21_EPS &&
      !exp_is_fin && !exp_is_nan) {
    return 1;
  }

  // pow(+1, exp) returns 1 for any exp, even when exp is NaN
  if (base_is_fin && !base_is_nan && s21_fabs(base - 1) < S21_EPS) {
    return 1;
  }

  // pow(base, ±0) returns 1 for any base, even when base is NaN
  if (s21_fabs(exp) < S21_EPS) {
    return 1;
  }

  // pow(base, exp) returns NaN and raises FE_INVALID if base is finite and
  // negative and exp is finite and non-integer.
  if (base_is_fin && base < -S21_EPS && exp_is_fin && !exp_min) {
    return S21_NAN;
  }

  // pow(base, -∞) returns +∞ for any |base|<1
  if (s21_fabs(base) - 1 < S21_EPS && !exp_is_nan && !exp_is_fin && exp < 0) {
    return S21_INF;
  }

  // pow(base, -∞) returns +0 for any |base|>1
  if (s21_fabs(base) - 1 > S21_EPS && !exp_is_nan && !exp_is_fin && exp < 0) {
    return +0;
  }

  // pow(base, +∞) returns +0 for any |base|<1
  if (s21_fabs(base) - 1 < S21_EPS && !exp_is_nan && !exp_is_fin && exp > 0) {
    return +0;
  }

  // pow(base, +∞) returns +∞ for any |base|>1
  if (s21_fabs(base) - 1 > S21_EPS && !exp_is_nan && !exp_is_fin && exp > 0) {
    return S21_INF;
  }

  // pow(-∞, exp) returns -0 if exp is a negative odd integer
  if (!base_is_nan && !base_is_fin && base < 0 && exp_min && exp < 0 &&
      ((int)exp) % 2) {
    return -0;
  }

  // pow(-∞, exp) returns +0 if exp is a negative non-integer or negative
  // even integer
  if (!base_is_nan && !base_is_fin && base < 0 &&
      ((!exp_min && exp < 0) || (exp_min && exp < 0 && !(((int)exp) % 2)))) {
    return +0;
  }

  // pow(-∞, exp) returns -∞ if exp is a positive odd integer
  if (!base_is_nan && !base_is_fin && base < 0 &&
      (exp_min && exp > 0 && ((int)exp) & 1)) {
    return -S21_INF;
  }

  // pow(-∞, exp) returns +∞ if exp is a positive non-integer or positive
  // even integer
  if (!base_is_nan && !base_is_fin && base < 0 &&
      ((!exp_min && exp > 0) || (exp_min && exp > 0 && !(((int)exp) % 2)))) {
    return +S21_INF;
  }

  // pow(+∞, exp) returns +0 for any negative exp
  if (!base_is_nan && !base_is_fin && base > 0 && exp < -S21_EPS) {
    return +0;
  }

  // pow(+∞, exp) returns +∞ for any positive exp
  if (!base_is_nan && !base_is_fin && base > 0 && exp > S21_EPS) {
    return +S21_INF;
  }

  if (base_is_nan || exp_is_nan) {
    return S21_NAN;
  }

  return -123.5;
}

long double s21_pow_int(long double base, long long int exp_int) {
  long double res;
  if (exp_int >= 0) {
    res = 1;
    while (exp_int) {
      if (exp_int & 1) {
        res *= base;
      }
      base *= base;
      exp_int >>= 1;
    }
  } else {
    res = 1 / s21_pow_int(base, -exp_int);
  }
  return res;
}

long double s21_pow(double base, double exp) {
  long double res;
  long double copy = base;
  if (is_inf(exp) && base == -1) {
    return (long double)(-base);
  }
  if (is_nan(exp) && base == 1.) {
    return 1;
  }
  if (is_inf(exp) && !is_fin(base)) {
    if (exp < 0) {
      return 0;
    } else {
      return S21_INF;
    }
  }
  if (s21_pow_helper(base, exp) != -123.5) {
    return s21_pow_helper(base, exp);
  }
  long long int copy_exp_int = (long long int)exp;
  if (s21_fabs(exp) - s21_abs_long_int(copy_exp_int) < 1e-7) {
    res = s21_pow_int(copy, copy_exp_int);
    return res;
  }
  if ((base < 0) && s21_fmod(exp, 1) != 0) {
    res = S21_NAN;
  } else if (exp == 0) {
    res = 1;
  } else if (base == 0 && exp > 0) {
    res = 0;
  } else {
    if (copy < 0) {
      copy = -copy;
      res = s21_exp(exp * s21_log(copy));
      if (s21_fmod(exp, 2) != 0) {
        res = -res;
      }
    } else {
      res = s21_exp(exp * s21_log(base));
    }
  }
  return res;
}
