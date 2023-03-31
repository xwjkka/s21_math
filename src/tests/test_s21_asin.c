#include "unit.h"

START_TEST(simple) {
  ck_assert_ldouble_eq_tol(s21_asin(0.5), asinl(0.5), 1e-7);
}
END_TEST

START_TEST(simple2) { ck_assert_ldouble_eq_tol(s21_asin(0), asinl(0), 1e-7); }
END_TEST

START_TEST(simple3) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.12331), asinl(-0.12331), 1e-7);
}
END_TEST

START_TEST(simple4) { ck_assert_ldouble_eq_tol(s21_asin(1), asinl(1), 1e-7); }
END_TEST

START_TEST(negative_1) {
  ck_assert_ldouble_eq_tol(s21_asin(-1), asinl(-1), 1e-7);
}
END_TEST

START_TEST(negative_2) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.9999), asinl(-0.9999), 1e-7);
}
END_TEST

START_TEST(negative_3) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.05123), asinl(-0.05123), 1e-7);
}
END_TEST

START_TEST(if_nan) {
  ck_assert_ldouble_nan(s21_asin(S21_NAN));
  ck_assert_ldouble_nan(asinl(S21_NAN));
}
END_TEST

START_TEST(if_nan2) {
  ck_assert_ldouble_nan(s21_asin(13));
  ck_assert_ldouble_nan(asinl(13));
}
END_TEST

START_TEST(if_nan3) {
  ck_assert_ldouble_nan(s21_asin(-2113.1231));
  ck_assert_ldouble_nan(asinl(-2113.1231));
}
END_TEST

START_TEST(if_inf1) {
  ck_assert_ldouble_nan(s21_asin(+S21_INFINITY));
  ck_assert_ldouble_nan(asinl(+S21_INFINITY));
}
END_TEST

START_TEST(if_inf2) {
  ck_assert_ldouble_nan(s21_asin(-S21_INFINITY));
  ck_assert_ldouble_nan(asinl(-S21_INFINITY));
}
END_TEST

START_TEST(hard_test) {
  long double step = 0.0241245456;
  long double x = 0.L;
  for (int i = 0; i < 25; i++) {
    x = x + step;
    ck_assert_ldouble_eq_tol(s21_asin(x), asinl(x), 1e-6);
  }
}
END_TEST

START_TEST(hard_test2) {
  long double step = 0.1241245456L;
  for (int i = 0; i < 3; i++) {
    step += step;
    ck_assert_ldouble_eq_tol(s21_asin(step), asinl(step), 1e-6);
  }
}
END_TEST

START_TEST(ultra_hard_test1) {
  ck_assert_ldouble_eq_tol(s21_asin(0.123236567), asinl(0.123236567), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test2) {
  ck_assert_ldouble_eq_tol(s21_asin(0.999), asinl(0.999), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test3) {
  ck_assert_ldouble_eq_tol(s21_asin(-0.7877899), asinl(-0.7877899), 1e-6);
}
END_TEST

Suite *suite_s21_asin() {
  Suite *s = suite_create("s21_asin");
  TCase *temp = tcase_create("test_asin");
  suite_add_tcase(s, temp);

  tcase_add_test(temp, simple);
  tcase_add_test(temp, simple2);
  tcase_add_test(temp, simple3);
  tcase_add_test(temp, simple4);
  tcase_add_test(temp, negative_1);
  tcase_add_test(temp, negative_2);
  tcase_add_test(temp, negative_3);
  tcase_add_test(temp, if_nan);
  tcase_add_test(temp, if_nan2);
  tcase_add_test(temp, if_nan3);
  tcase_add_test(temp, if_inf1);
  tcase_add_test(temp, if_inf2);
  tcase_add_test(temp, hard_test);
  tcase_add_test(temp, hard_test2);
  tcase_add_test(temp, ultra_hard_test1);
  tcase_add_test(temp, ultra_hard_test2);
  tcase_add_test(temp, ultra_hard_test3);

  return s;
}