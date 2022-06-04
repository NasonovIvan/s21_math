#include "math_suitecases.h"

START_TEST(atan_1) { ck_assert_float_eq(s21_atan(-15.01), atan(-15.01)); }
END_TEST

START_TEST(atan_2) {
  double num = -0.99;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_3) { ck_assert_float_eq(-9999999999, -9999999999); }
END_TEST
START_TEST(atan_4) {
  ck_assert_ldouble_eq(s21_atan(INFINITY), atan(INFINITY));
  ck_assert_ldouble_eq(s21_atan(-INFINITY), atan(-INFINITY));
}
END_TEST

START_TEST(atan_5) {
  double num = NAN;
  long double orig_res = s21_atan(num), our_res = atan(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(atan_6) {
  ck_assert_ldouble_eq_tol(s21_atan(INFINITY), (M_PI / 2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(INFINITY), (M_PI / 2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan((-INFINITY)), ((M_PI) / -2.0), S21_EPS);
  ck_assert_ldouble_eq_tol(atan(-INFINITY), ((M_PI) / -2.0), S21_EPS);
}
END_TEST

START_TEST(atan_7) {
  ck_assert_ldouble_nan(s21_atan(NAN));
  ck_assert_ldouble_nan(atan(NAN));
}
END_TEST

START_TEST(atan_8) {
  ck_assert_ldouble_eq_tol(s21_atan(1.0), atan(1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(1.1), atan(1.1), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-1.0), atan(-1.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-1.1), atan(-1.1), S21_EPS);
}
END_TEST

START_TEST(atan_9) {
  ck_assert_ldouble_eq_tol(s21_atan(0.0), atan(0.0), S21_EPS);
  ck_assert_ldouble_eq_tol(s21_atan(-0.0), atan(-0.0), S21_EPS);
}
END_TEST

START_TEST(atan_10) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), S21_EPS);
}
END_TEST

START_TEST(atan_11) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(3) / 2), atan(-sqrt(3) / 2), S21_EPS);
}
END_TEST

START_TEST(atan_12) {
  ck_assert_ldouble_eq_tol(s21_atan(-sqrt(2) / 2), atan(-sqrt(2) / 2), S21_EPS);
}
END_TEST

START_TEST(atan_13) {
  ck_assert_ldouble_eq_tol(s21_atan(-1 / 2), atan(-1 / 2), S21_EPS);
}
END_TEST

START_TEST(atan_14) {
  ck_assert_ldouble_eq_tol(s21_atan(1 / 2), atan(1 / 2), S21_EPS);
}
END_TEST

START_TEST(atan_15) {
  ck_assert_ldouble_eq_tol(s21_atan(2 / 2), atan(2 / 2), S21_EPS);
}
END_TEST

START_TEST(atan_16) {
  ck_assert_ldouble_eq_tol(s21_atan(sqrt(3) / 2), atan(sqrt(3) / 2), S21_EPS);
}
END_TEST

START_TEST(atan_17) { ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), S21_EPS); }
END_TEST

START_TEST(atan_18) {
  ck_assert_ldouble_eq_tol(s21_atan(1.23456e-7), atan(1.23456e-7), S21_EPS);
}
END_TEST

START_TEST(atan_19) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567), atan(2.1234567), S21_EPS);
}
END_TEST

START_TEST(atan_20) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-7), atan(2.1234567e-7), S21_EPS);
}
END_TEST

START_TEST(atan_21) {
  ck_assert_ldouble_eq_tol(s21_atan(2.1234567e-16), atan(2.1234567e-16),
                           S21_EPS);
}
END_TEST

START_TEST(atan_22) { ck_assert_float_nan(s21_atan(S21_NAN)); }
END_TEST

START_TEST(atan_23) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_PI / 2), atan(S21_PI / 2), S21_EPS);
}
END_TEST

START_TEST(atan_24) {
  ck_assert_ldouble_eq_tol(s21_atan(-S21_PI / 2), atan(-S21_PI / 2), S21_EPS);
}
END_TEST

Suite *suite_s21_atan(void) {
  Suite *s4;
  TCase *tc4;
  s4 = suite_create("s21_atan");
  tc4 = tcase_create("case_atan");

  tcase_add_test(tc4, atan_1);
  tcase_add_test(tc4, atan_2);
  tcase_add_test(tc4, atan_3);
  tcase_add_test(tc4, atan_4);
  tcase_add_test(tc4, atan_5);
  tcase_add_test(tc4, atan_6);
  tcase_add_test(tc4, atan_7);
  tcase_add_test(tc4, atan_8);
  tcase_add_test(tc4, atan_9);
  tcase_add_test(tc4, atan_10);
  tcase_add_test(tc4, atan_11);
  tcase_add_test(tc4, atan_12);
  tcase_add_test(tc4, atan_13);
  tcase_add_test(tc4, atan_14);
  tcase_add_test(tc4, atan_15);
  tcase_add_test(tc4, atan_16);
  tcase_add_test(tc4, atan_17);
  tcase_add_test(tc4, atan_18);
  tcase_add_test(tc4, atan_19);
  tcase_add_test(tc4, atan_20);
  tcase_add_test(tc4, atan_21);
  tcase_add_test(tc4, atan_22);
  tcase_add_test(tc4, atan_23);
  tcase_add_test(tc4, atan_24);

  suite_add_tcase(s4, tc4);
  return s4;
}
