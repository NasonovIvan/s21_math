#include "math_suitecases.h"

START_TEST(sin_1) {
  double num = 0.55;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_2) { ck_assert_float_eq(s21_sin(0), sin(0)); }
END_TEST

START_TEST(sin_3) {
  double num = 1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_4) {
  double num = -1;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_5) {
  double num = 0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_6) {
  double num = -0.999999;
  long double orig_res = s21_sin(num), our_res = s21_sin(num);
  int suc = 0;
  if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_7) {
  double num = NAN;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_8) {
  double num = INFINITY;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_9) {
  double num = -INFINITY;
  long double orig_res = sin(num), our_res = s21_sin(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(sin_10) {
  double x = 0;
  ck_assert_double_eq_tol(s21_sin(x), sinl(x), 1e-06);
}
END_TEST

START_TEST(sin_11) {
  ck_assert_ldouble_nan(s21_sin(-INFINITY));
  ck_assert_ldouble_nan(sinl(-INFINITY));
}
END_TEST

START_TEST(sin_12) {
  ck_assert_ldouble_nan(s21_sin(INFINITY));
  ck_assert_ldouble_nan(sinl(INFINITY));
}
END_TEST

START_TEST(sin_13) {
  ck_assert_ldouble_nan(s21_sin(NAN));
  ck_assert_ldouble_nan(sinl(NAN));
}
END_TEST

START_TEST(sin_14) { ck_assert_double_eq_tol(s21_sin(0.0), sin(0.0), 1e-06); }
END_TEST

START_TEST(sin_15) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 6), sin(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(sin_16) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 4), sin(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(sin_17) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 3), sin(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(sin_18) {
  ck_assert_double_eq_tol(s21_sin(M_PI / 2), sin(M_PI / 2), 1e-06);
}
END_TEST

START_TEST(sin_19) {
  ck_assert_double_eq_tol(s21_sin(3 * M_PI / 2), sin(3 * M_PI / 2), 1e-06);
}
END_TEST

START_TEST(sin_20) {
  ck_assert_double_eq_tol(s21_sin(2 * M_PI), sin(2 * M_PI), 1e-06);
}
END_TEST

START_TEST(sin_21) {
  ck_assert_double_eq_tol(s21_sin(-2 * M_PI), sin(-2 * M_PI), 1e-06);
}
END_TEST

START_TEST(sin_22) {
  ck_assert_double_eq_tol(s21_sin(-3 * M_PI), sin(-3 * M_PI), 1e-06);
}
END_TEST

START_TEST(sin_23) {
  ck_assert_double_eq_tol(s21_sin(174.532925199433), sin(174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(sin_24) {
  ck_assert_double_eq_tol(s21_sin(-174.532925199433), sin(-174.532925199433),
                          1e-06);
}
END_TEST

START_TEST(sin_25) {
  ck_assert_double_eq_tol(s21_sin(-S21_PI), sin(-S21_PI), 1e-06);
}
END_TEST

Suite *suite_s21_sin(void) {
  Suite *s13;
  TCase *tc13;
  s13 = suite_create("s21_sin");
  tc13 = tcase_create("case_sin");

  tcase_add_test(tc13, sin_1);
  tcase_add_test(tc13, sin_2);
  tcase_add_test(tc13, sin_3);
  tcase_add_test(tc13, sin_4);
  tcase_add_test(tc13, sin_5);
  tcase_add_test(tc13, sin_6);
  tcase_add_test(tc13, sin_7);
  tcase_add_test(tc13, sin_8);
  tcase_add_test(tc13, sin_9);
  tcase_add_test(tc13, sin_10);
  tcase_add_test(tc13, sin_11);
  tcase_add_test(tc13, sin_12);
  tcase_add_test(tc13, sin_13);
  tcase_add_test(tc13, sin_14);
  tcase_add_test(tc13, sin_15);
  tcase_add_test(tc13, sin_16);
  tcase_add_test(tc13, sin_17);
  tcase_add_test(tc13, sin_18);
  tcase_add_test(tc13, sin_19);
  tcase_add_test(tc13, sin_20);
  tcase_add_test(tc13, sin_21);
  tcase_add_test(tc13, sin_22);
  tcase_add_test(tc13, sin_23);
  tcase_add_test(tc13, sin_24);
  tcase_add_test(tc13, sin_25);

  suite_add_tcase(s13, tc13);
  return s13;
}
