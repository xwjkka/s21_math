#include "unit.h"

START_TEST(simple) { ck_assert_ldouble_eq_tol(s21_sin(1), sinl(1), 1e-7); }
END_TEST

START_TEST(simple2) { ck_assert_ldouble_eq_tol(s21_sin(0), sinl(0), 1e-7); }
END_TEST

START_TEST(simple3) {
  ck_assert_ldouble_eq_tol(s21_sin(S21_M_PI), sinl(S21_M_PI), 1e-7);
}
END_TEST

START_TEST(simple4) {
  ck_assert_ldouble_eq_tol(s21_sin(1e10), sin(1e10), 1e-6);
}
END_TEST

START_TEST(if_nan) {
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
  ck_assert_ldouble_nan(sinl(S21_NAN));
}
END_TEST

START_TEST(if_inf1) {
  ck_assert_ldouble_nan(s21_sin(+S21_INFINITY));
  ck_assert_ldouble_nan(sinl(+S21_INFINITY));
}
END_TEST

START_TEST(if_inf2) {
  ck_assert_ldouble_nan(s21_sin(-S21_INFINITY));
  ck_assert_ldouble_nan(sinl(-S21_INFINITY));
}
END_TEST

START_TEST(hard_test) {
  long double step = 0.1241245456;
  long double x = 2.L;
  for (int i = 0; i < 50; i++) {
    x = x + step;
    ck_assert_ldouble_eq_tol(s21_sin(x), sinl(x), 1e-6);
  }
}
END_TEST

START_TEST(hard_test2) {
  long double step = 0.1241245456L;
  for (int i = 0; i < 25; i++) {
    step += step;
    ck_assert_ldouble_eq_tol(s21_sin(step), sinl(step), 1e-6);
  }
}
END_TEST

START_TEST(ultra_hard_test1) {
  ck_assert_ldouble_eq_tol(s21_sin(2343.123236567), sinl(2343.123236567), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test2) {
  ck_assert_ldouble_eq_tol(s21_sin(-171231.228941), sinl(-171231.228941), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test3) {
  long double step = -0.53258643L;
  for (int i = 0; i < 25; i++) {
    step -= step;
    ck_assert_ldouble_eq_tol(s21_sin(step), sinl(step), 1e-6);
  }
}
END_TEST

Suite *suite_s21_sin() {
  Suite *s = suite_create("s21_sin");
  TCase *temp = tcase_create("test_sin");
  suite_add_tcase(s, temp);

  tcase_add_test(temp, simple);
  tcase_add_test(temp, simple2);
  tcase_add_test(temp, simple3);
  tcase_add_test(temp, simple4);
  tcase_add_test(temp, if_nan);
  tcase_add_test(temp, if_inf1);
  tcase_add_test(temp, if_inf2);
  tcase_add_test(temp, hard_test);
  tcase_add_test(temp, hard_test2);
  tcase_add_test(temp, ultra_hard_test1);
  tcase_add_test(temp, ultra_hard_test2);
  tcase_add_test(temp, ultra_hard_test3);

  return s;
}
