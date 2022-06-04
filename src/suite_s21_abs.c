#include "math_suitecases.h"

START_TEST(abs_1) { ck_assert_int_eq(s21_abs(21), abs(21)); }
END_TEST

START_TEST(abs_2) { ck_assert_int_eq(s21_abs(-21), abs(-21)); }
END_TEST

START_TEST(abs_3) { ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647)); }
END_TEST

START_TEST(abs_4) { ck_assert_int_eq(s21_abs(2147483647), abs(2147483647)); }
END_TEST

START_TEST(abs_5) { ck_assert_int_eq(s21_abs(-0), abs(-0)); }
END_TEST

START_TEST(abs_6) { ck_assert_int_eq(s21_abs(+0), abs(+0)); }
END_TEST

START_TEST(abs_7) { ck_assert_int_eq(s21_abs((int)NAN), abs((int)NAN)); }
END_TEST

START_TEST(abs_8) {
  ck_assert_int_eq(s21_abs((int)INFINITY), abs((int)INFINITY));
}
END_TEST

START_TEST(abs_9) {
  ck_assert_int_eq(s21_abs((int)-INFINITY), abs((int)-INFINITY));
}
END_TEST

START_TEST(abs_10) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

Suite *suite_s21_abs(void) {
  Suite *s1;
  TCase *tc1;
  s1 = suite_create("s21_abs");

  tc1 = tcase_create("case_abs");

  tcase_add_test(tc1, abs_1);
  tcase_add_test(tc1, abs_2);
  tcase_add_test(tc1, abs_3);
  tcase_add_test(tc1, abs_4);
  tcase_add_test(tc1, abs_5);
  tcase_add_test(tc1, abs_6);
  tcase_add_test(tc1, abs_7);
  tcase_add_test(tc1, abs_8);
  tcase_add_test(tc1, abs_9);
  tcase_add_test(tc1, abs_10);

  suite_add_tcase(s1, tc1);
  return s1;
}
