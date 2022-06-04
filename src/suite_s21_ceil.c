#include "math_suitecases.h"

START_TEST(ceil_1) { ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01)); }
END_TEST

START_TEST(ceil_2) { ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01)); }
END_TEST

START_TEST(ceil_3) { ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY)); }
END_TEST

START_TEST(ceil_4) {
  ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
}
END_TEST

START_TEST(ceil_5) { ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12)); }
END_TEST

START_TEST(ceil_6) {
  double num = NAN;
  long double orig_res = ceil(num), our_res = s21_ceil(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(ceil_7) {
  ck_assert_ldouble_infinite(s21_ceil(INFINITY));
  ck_assert_ldouble_infinite(ceil(INFINITY));
}
END_TEST

START_TEST(ceil_8) {
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_nan(ceil(NAN));
}
END_TEST

START_TEST(ceil_9) { ck_assert_ldouble_eq(s21_ceil(0), ceil(0)); }
END_TEST

START_TEST(ceil_11) { ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0)); }
END_TEST

START_TEST(ceil_12) { ck_assert_ldouble_eq(s21_ceil(21.21), ceil(21.21)); }
END_TEST

START_TEST(ceil_13) { ck_assert_ldouble_eq(s21_ceil(21.91), ceil(21.91)); }
END_TEST

START_TEST(ceil_14) { ck_assert_ldouble_eq(s21_ceil(-21.21), ceil(-21.21)); }
END_TEST

START_TEST(ceil_15) { ck_assert_ldouble_eq(s21_ceil(-21.91), ceil(-21.91)); }
END_TEST

START_TEST(ceil_16) { ck_assert_ldouble_eq(s21_ceil(DBL_MAX), ceil(DBL_MAX)); }
END_TEST

Suite *suite_s21_ceil(void) {
  Suite *s5;
  TCase *tc5;
  s5 = suite_create("s21_ceil");
  tc5 = tcase_create("case_ceil");

  tcase_add_test(tc5, ceil_1);
  tcase_add_test(tc5, ceil_2);
  tcase_add_test(tc5, ceil_3);
  tcase_add_test(tc5, ceil_4);
  tcase_add_test(tc5, ceil_5);
  tcase_add_test(tc5, ceil_6);
  tcase_add_test(tc5, ceil_7);
  tcase_add_test(tc5, ceil_8);
  tcase_add_test(tc5, ceil_9);
  tcase_add_test(tc5, ceil_11);
  tcase_add_test(tc5, ceil_12);
  tcase_add_test(tc5, ceil_13);
  tcase_add_test(tc5, ceil_14);
  tcase_add_test(tc5, ceil_15);
  tcase_add_test(tc5, ceil_16);

  suite_add_tcase(s5, tc5);
  return s5;
}
