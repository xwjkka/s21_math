#include "unit.h"

START_TEST(simple) { ck_assert_ldouble_eq_tol(s21_floor(1), floorl(1), 1e-6); }
END_TEST

START_TEST(simple2) { ck_assert_ldouble_eq_tol(s21_floor(0), floorl(0), 1e-6); }
END_TEST

START_TEST(simple3) {
  ck_assert_ldouble_eq_tol(s21_floor(0.1), floorl(0.1), 1e-6);
}
END_TEST

START_TEST(simple4) {
  ck_assert_ldouble_eq_tol(s21_floor(S21_M_PI_2), floorl(S21_M_PI_2), 1e-6);
}
END_TEST

START_TEST(if_nan) {
  ck_assert_ldouble_nan(s21_floor(S21_NAN));
  ck_assert_ldouble_nan(floorl(S21_NAN));
}
END_TEST

START_TEST(if_inf1) {
  ck_assert_ldouble_infinite(s21_floor(+S21_INFINITY));
  ck_assert_ldouble_infinite(floorl(+S21_INFINITY));
}
END_TEST

START_TEST(if_inf2) {
  ck_assert_ldouble_infinite(s21_floor(-S21_INFINITY));
  ck_assert_ldouble_infinite(floorl(-S21_INFINITY));
}
END_TEST

START_TEST(negative_num1) {
  ck_assert_ldouble_eq_tol(s21_floor(-1.2), floorl(-1.2), 1e-6);
}
END_TEST

START_TEST(negative_num2) {
  ck_assert_ldouble_eq_tol(s21_floor(-53), floorl(-53), 1e-6);
}
END_TEST

START_TEST(negative_num3) {
  ck_assert_ldouble_eq_tol(s21_floor(-55 + S21_EPS), floorl(-55 + S21_EPS),
                           1e-6);
}
END_TEST

START_TEST(negative_num4) {
  ck_assert_ldouble_eq_tol(s21_floor(-55 + 1e-6), floorl(-55 + 1e-6), 1e-6);
}
END_TEST

START_TEST(negative_num5) {
  ck_assert_ldouble_eq_tol(s21_floor(-0.1), floorl(-0.1), 1e-6);
}
END_TEST

Suite *suite_s21_floor() {
  Suite *s = suite_create("s21_floor");
  TCase *temp = tcase_create("test_floor");
  suite_add_tcase(s, temp);

  tcase_add_test(temp, simple);
  tcase_add_test(temp, simple2);
  tcase_add_test(temp, simple3);
  tcase_add_test(temp, simple4);
  tcase_add_test(temp, if_nan);
  tcase_add_test(temp, if_inf1);
  tcase_add_test(temp, if_inf2);
  tcase_add_test(temp, negative_num1);
  tcase_add_test(temp, negative_num2);
  tcase_add_test(temp, negative_num3);
  tcase_add_test(temp, negative_num4);
  tcase_add_test(temp, negative_num5);

  return s;
}
