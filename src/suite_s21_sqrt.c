#include "math_suitecases.h"

START_TEST(sqrt_1) {
    double num = INFINITY;
    long double orig_res = sqrt(num), our_res = s21_sqrt(num);
    int suc = 0;
    if (isinf(orig_res) && isinf(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(sqrt_2) {
    double num = -INFINITY;
    long double orig_res = sqrt(num), our_res = s21_sqrt(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(sqrt_3) {
    double num = -15.01;
    ck_assert_ldouble_nan(s21_sqrt(num));
    ck_assert_ldouble_nan(sqrt(num));
} END_TEST

START_TEST(sqrt_4) {
    double num = 0.9999;
    long double orig_res = sqrt(num), our_res = s21_sqrt(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(sqrt_5) {
    double num = NAN;
    long double orig_res = sqrt(num), our_res = s21_sqrt(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
} END_TEST

START_TEST(sqrt_6) {
    ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
    ck_assert_ldouble_infinite(sqrt(INFINITY));
}
END_TEST

START_TEST(sqrt_7) {
    ck_assert_ldouble_nan(s21_sqrt(NAN));
    ck_assert_ldouble_nan(sqrt(NAN));
}
END_TEST

START_TEST(sqrt_8) {
    ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), 1e-6);
}
END_TEST

START_TEST(sqrt_9) {
    ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), 1e-6);
    ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), 1e-6);
} END_TEST

START_TEST(sqrt_10) {
    ck_assert_ldouble_eq_tol(s21_sqrt(10e+16), sqrt(10e+16), 1e-6);
} END_TEST

START_TEST(sqrt_12) {
    ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-6);
} END_TEST

START_TEST(sqrt_13) {
    ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), 1e-6);
} END_TEST

START_TEST(sqrt_14) {
    ck_assert_ldouble_eq_tol(s21_sqrt(98765432.123), sqrt(98765432.123), 1e-6);
} END_TEST

START_TEST(sqrt_15) {
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e6), sqrt(981.123e6), 1e-6);
} END_TEST

START_TEST(sqrt_16) {
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e-15), sqrt(981.123e-15), 1e-6);
} END_TEST

  Suite * suite_s21_sqrt(void) {
    Suite *s14;
    TCase *tc14;
    s14 = suite_create("s21_sqrt");
    tc14 = tcase_create("case_sqrt");

    tcase_add_test(tc14, sqrt_1);
    tcase_add_test(tc14, sqrt_2);
    tcase_add_test(tc14, sqrt_3);
    tcase_add_test(tc14, sqrt_4);
    tcase_add_test(tc14, sqrt_5);
    tcase_add_test(tc14, sqrt_6);
    tcase_add_test(tc14, sqrt_7);
    tcase_add_test(tc14, sqrt_8);
    tcase_add_test(tc14, sqrt_9);
    tcase_add_test(tc14, sqrt_10);
    tcase_add_test(tc14, sqrt_12);
    tcase_add_test(tc14, sqrt_13);
    tcase_add_test(tc14, sqrt_14);
    tcase_add_test(tc14, sqrt_15);
    tcase_add_test(tc14, sqrt_16);

    suite_add_tcase(s14, tc14);
    return s14;
}
