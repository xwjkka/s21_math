#include "unit.h"

START_TEST(simple) {
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acosl(0.5), 1e-7);
}
END_TEST

START_TEST(simple2) { ck_assert_ldouble_eq_tol(s21_acos(0), acosl(0), 1e-7); }
END_TEST

START_TEST(simple3) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.12331), acosl(-0.12331), 1e-7);
}
END_TEST

START_TEST(simple4) { ck_assert_ldouble_eq_tol(s21_acos(1), acosl(1), 1e-7); }
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
  ck_assert_ldouble_nan(s21_acos(S21_NAN));
  ck_assert_ldouble_nan(acosl(S21_NAN));
}
END_TEST

START_TEST(if_nan2) {
  ck_assert_ldouble_nan(s21_acos(13));
  ck_assert_ldouble_nan(acosl(13));
}
END_TEST

START_TEST(if_nan3) {
  ck_assert_ldouble_nan(s21_acos(-2113.1231));
  ck_assert_ldouble_nan(acosl(-2113.1231));
}
END_TEST

START_TEST(if_inf1) {
  ck_assert_ldouble_nan(s21_acos(+S21_INFINITY));
  ck_assert_ldouble_nan(acosl(+S21_INFINITY));
}
END_TEST

START_TEST(if_inf2) {
  ck_assert_ldouble_nan(s21_acos(-S21_INFINITY));
  ck_assert_ldouble_nan(acosl(-S21_INFINITY));
}
END_TEST

START_TEST(hard_test) {
  long double step = 0.0241245456;
  long double x = 0.L;
  for (int i = 0; i < 25; i++) {
    x = x + step;
    ck_assert_ldouble_eq_tol(s21_acos(x), acosl(x), 1e-6);
  }
}
END_TEST

START_TEST(hard_test2) {
  long double step = 0.1241245456L;
  for (int i = 0; i < 3; i++) {
    step += step;
    ck_assert_ldouble_eq_tol(s21_acos(step), acosl(step), 1e-6);
  }
}
END_TEST

START_TEST(ultra_hard_test1) {
  ck_assert_ldouble_eq_tol(s21_acos(0.123236567), acosl(0.123236567), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test2) {
  ck_assert_ldouble_eq_tol(s21_acos(0.999), acosl(0.999), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test3) {
  ck_assert_ldouble_eq_tol(s21_acos(-0.7877899), acosl(-0.7877899), 1e-6);
}
END_TEST

Suite *suite_s21_acos() {
  Suite *s = suite_create("s21_acos");
  TCase *temp = tcase_create("test_acos");
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