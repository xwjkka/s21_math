#include "unit.h"

START_TEST(simple) { ck_assert_ldouble_eq_tol(s21_tan(1), tanl(1), 1e-7); }
END_TEST

START_TEST(simple2) { ck_assert_ldouble_eq_tol(s21_tan(0), tanl(0), 1e-7); }
END_TEST

START_TEST(simple3) {
  ck_assert_ldouble_eq_tol(s21_tan(S21_M_PI), tanl(S21_M_PI), 1e-7);
}
END_TEST

START_TEST(simple4) {
  ck_assert_ldouble_eq_tol(s21_tan(1e10), tan(1e10), 1e-6);
}
END_TEST

START_TEST(simple5) {
  ck_assert_ldouble_eq_tol(s21_tan(S21_M_PI_4), tanl(S21_M_PI_4), 1e-06);
}
END_TEST

START_TEST(simple6) {
  ck_assert_ldouble_eq_tol(s21_tan(-1e10), tan(-1e10), 1e-6);
}
END_TEST

START_TEST(if_nan) {
  ck_assert_ldouble_nan(s21_tan(S21_NAN));
  ck_assert_ldouble_nan(tanl(S21_NAN));
}
END_TEST

START_TEST(if_inf1) {
  ck_assert_ldouble_nan(s21_tan(+S21_INFINITY));
  ck_assert_ldouble_nan(tanl(+S21_INFINITY));
}
END_TEST

START_TEST(if_inf2) {
  ck_assert_ldouble_nan(s21_tan(-S21_INFINITY));
  ck_assert_ldouble_nan(tanl(-S21_INFINITY));
}
END_TEST

START_TEST(hard_test) {
  long double step = 0.1241245456;
  long double x = 2.L;
  for (int i = 0; i < 50; i++) {
    x = x + step;
    ck_assert_ldouble_eq_tol(s21_tan(x), tanl(x), 1e-6);
  }
}
END_TEST

START_TEST(hard_test2) {
  long double step = 0.1241245456L;
  for (int i = 0; i < 25; i++) {
    step += step;
    ck_assert_ldouble_eq_tol(s21_tan(step), tanl(step), 1e-6);
  }
}
END_TEST

START_TEST(ultra_hard_test1) {
  ck_assert_ldouble_eq_tol(s21_tan(2343.123236567), tanl(2343.123236567), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test2) {
  ck_assert_ldouble_eq_tol(s21_tan(-171231.228941), tanl(-171231.228941), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test3) {
  long double step = -0.53258643L;
  for (int i = 0; i < 25; i++) {
    step -= step;
    ck_assert_ldouble_eq_tol(s21_tan(step), tanl(step), 1e-6);
  }
}
END_TEST

Suite *suite_s21_tan() {
  Suite *s = suite_create("s21_tan");
  TCase *temp = tcase_create("test_tan");
  suite_add_tcase(s, temp);

  tcase_add_test(temp, simple);
  tcase_add_test(temp, simple2);
  tcase_add_test(temp, simple3);
  tcase_add_test(temp, simple4);
  tcase_add_test(temp, simple5);
  tcase_add_test(temp, simple6);
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
