#include "math_suitecases.h"

START_TEST(floor_1) { ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0)); }
END_TEST

START_TEST(floor_2) { ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21)); }
END_TEST

START_TEST(floor_3) { ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91)); }
END_TEST

START_TEST(floor_4) { ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21)); }
END_TEST

START_TEST(floor_5) { ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91)); }
END_TEST

START_TEST(floor_6) {
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
  ck_assert_ldouble_infinite(floor(INFINITY));
}
END_TEST

START_TEST(floor_7) {
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_nan(floor(NAN));
}
END_TEST

START_TEST(floor_8) { ck_assert_ldouble_eq(s21_floor(0), floor(0)); }
END_TEST

START_TEST(floor_10) { ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01)); }
END_TEST

START_TEST(floor_11) { ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01)); }
END_TEST

START_TEST(floor_12) {
  ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
}
END_TEST

START_TEST(floor_13) {
  ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
}
END_TEST

START_TEST(floor_14) {
  double num = NAN;
  long double orig_res = floor(num), our_res = s21_floor(num);
  int suc = 0;
  if (isnan(orig_res) && isnan(our_res)) suc = 1;
  ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(floor_15) { ck_assert_ldouble_eq(s21_floor(-0), floor(-0)); }
END_TEST

Suite *suite_s21_floor(void) {
  Suite *s9;
  TCase *tc9;
  s9 = suite_create("s21_floor");

  tc9 = tcase_create("case_floor");

  tcase_add_test(tc9, floor_1);
  tcase_add_test(tc9, floor_2);
  tcase_add_test(tc9, floor_3);
  tcase_add_test(tc9, floor_4);
  tcase_add_test(tc9, floor_5);
  tcase_add_test(tc9, floor_6);
  tcase_add_test(tc9, floor_7);
  tcase_add_test(tc9, floor_8);
  tcase_add_test(tc9, floor_10);
  tcase_add_test(tc9, floor_11);
  tcase_add_test(tc9, floor_12);
  tcase_add_test(tc9, floor_13);
  tcase_add_test(tc9, floor_14);
  tcase_add_test(tc9, floor_15);

  suite_add_tcase(s9, tc9);
  return s9;
}
