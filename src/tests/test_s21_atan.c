#include "unit.h"

START_TEST(simple) {
  ck_assert_ldouble_eq_tol(s21_atan(0.5), atanl(0.5), 1e-7);
}
END_TEST

START_TEST(simple2) { ck_assert_ldouble_eq_tol(s21_atan(0), atanl(0), 1e-7); }
END_TEST

START_TEST(simple3) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.12331), atanl(-0.12331), 1e-7);
}
END_TEST

START_TEST(simple4) { ck_assert_ldouble_eq_tol(s21_atan(1), atanl(1), 1e-7); }
END_TEST

START_TEST(negative_1) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atanl(-1), 1e-6);
}
END_TEST

START_TEST(negative_2) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.999), atanl(-0.999), 1e-6);
}
END_TEST

START_TEST(negative_3) {
  ck_assert_ldouble_eq_tol(s21_atan(-322.123), atanl(-322.123), 1e-6);
}
END_TEST

START_TEST(if_nan) {
  ck_assert_ldouble_nan(s21_atan(S21_NAN));
  ck_assert_ldouble_nan(atanl(S21_NAN));
}
END_TEST

START_TEST(if_inf1) {
  ck_assert_ldouble_eq_tol(s21_atan(+S21_INFINITY), atanl(+S21_INFINITY), 1e-6);
}
END_TEST

START_TEST(if_inf2) {
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INFINITY), atanl(-S21_INFINITY), 1e-6);
}
END_TEST

START_TEST(hard_test) {
  long double step = 0.0241245456;
  long double x = 0.L;
  for (int i = 0; i < 25; i++) {
    x = x + step;
    ck_assert_ldouble_eq_tol(s21_atan(x), atanl(x), 1e-6);
  }
}
END_TEST

START_TEST(hard_test2) {
  long double step = 0.1241245456L;
  for (int i = 0; i < 3; i++) {
    step += step;
    ck_assert_ldouble_eq_tol(s21_atan(step), atanl(step), 1e-6);
  }
}
END_TEST

START_TEST(ultra_hard_test1) {
  ck_assert_ldouble_eq_tol(s21_atan(0.123236567), atanl(0.123236567), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test2) {
  ck_assert_ldouble_eq_tol(s21_atan(0.999), atanl(0.999), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test3) {
  ck_assert_ldouble_eq_tol(s21_atan(-0.7877899), atanl(-0.7877899), 1e-6);
}
END_TEST

Suite *suite_s21_atan() {
  Suite *s = suite_create("s21_atan");
  TCase *temp = tcase_create("test_atan");
  suite_add_tcase(s, temp);

  tcase_add_test(temp, simple);
  tcase_add_test(temp, simple2);
  tcase_add_test(temp, simple3);
  tcase_add_test(temp, simple4);
  tcase_add_test(temp, negative_1);
  tcase_add_test(temp, negative_2);
  tcase_add_test(temp, negative_3);
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