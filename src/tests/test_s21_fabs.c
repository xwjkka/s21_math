#include "unit.h"

START_TEST(positive) {
  ck_assert_ldouble_eq_tol(fabs(1234.8349), s21_fabs(1234.8349), 1e-7);
}
END_TEST

START_TEST(negative) {
  ck_assert_ldouble_eq_tol(fabs(-1234.8349), s21_fabs(-1234.8349), 1e-7);
}
END_TEST

START_TEST(fabst) {
  double x = 3273.489729;
  for (int i = 0; i < 100; i++) {
    ck_assert_ldouble_eq_tol(fabs(x), s21_fabs(x), 1e-7);
    x -= 73.562;
  }
  ck_assert_ldouble_eq_tol(fabs(x), s21_fabs(x), 1e-7);
}
END_TEST

START_TEST(if_nan) {
  ck_assert_ldouble_nan(s21_fabs(S21_NAN));
  ck_assert_ldouble_nan(fabsl(S21_NAN));
}
END_TEST

START_TEST(if_inf1) {
  ck_assert_ldouble_infinite(s21_fabs(+S21_INFINITY));
  ck_assert_ldouble_infinite(fabsl(+S21_INFINITY));
}
END_TEST

START_TEST(if_inf2) {
  ck_assert_ldouble_infinite(s21_fabs(-S21_INFINITY));
  ck_assert_ldouble_infinite(fabsl(-S21_INFINITY));
}
END_TEST

START_TEST(hard_test) {
  long double step = 0.1241245456;
  long double x = 2.L;
  for (int i = 0; i < 50; i++) {
    x = x + step;
    ck_assert_ldouble_eq_tol(s21_fabs(x), fabsl(x), 1e-6);
  }
}
END_TEST

START_TEST(hard_test2) {
  long double step = 0.1241245456;
  long double x = 2.L;
  for (int i = 0; i < 50; i++) {
    x = x - step;
    ck_assert_ldouble_eq_tol(s21_fabs(x), fabsl(x), 1e-6);
  }
}
END_TEST

START_TEST(ultra_hard1) {
  ck_assert_ldouble_eq_tol(fabs(0.), s21_fabs(0.), 1e-7);
}
END_TEST

Suite *suite_s21_fabs() {
  Suite *s = suite_create("s21_fabs");
  TCase *temp = tcase_create("test_fabs");
  suite_add_tcase(s, temp);

  tcase_add_test(temp, positive);
  tcase_add_test(temp, negative);
  tcase_add_test(temp, fabst);
  tcase_add_test(temp, if_nan);
  tcase_add_test(temp, if_inf1);
  tcase_add_test(temp, if_inf2);
  tcase_add_test(temp, hard_test);
  tcase_add_test(temp, hard_test2);
  tcase_add_test(temp, ultra_hard1);

  return s;
}