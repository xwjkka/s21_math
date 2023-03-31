#include "unit.h"

START_TEST(simple) {
  ck_assert_ldouble_eq_tol(powl(1.213, 2.3298), s21_pow(1.213, 2.3298), 1e-7);
}
END_TEST

START_TEST(s2) {
  ck_assert_ldouble_eq_tol(powl(1231, 2), s21_pow(1231, 2), 1e-7);
}
END_TEST

START_TEST(s3) {
  ck_assert_ldouble_eq_tol(powl(23.43, 3), s21_pow(23.43, 3), 1e-7);
}
END_TEST

START_TEST(s4) { ck_assert_ldouble_nan(s21_pow(-12, 8.3)); }
END_TEST

START_TEST(s5) {
  ck_assert_ldouble_eq_tol(powl(1, NAN), s21_pow(1, NAN), 1e-7);
}
END_TEST

START_TEST(s6) {
  ck_assert_ldouble_infinite(powl(0, -1));
  ck_assert_ldouble_infinite(s21_pow(0, -1));
}
END_TEST

START_TEST(s7) {
  ck_assert_ldouble_eq_tol(powl(NAN, 0), s21_pow(NAN, 0), 1e-7);
}
END_TEST

START_TEST(s8) {
  ck_assert_ldouble_nan(powl(-1234, 3289.23));
  ck_assert_ldouble_nan(s21_pow(-1234, 3289.23));
}
END_TEST

START_TEST(s9) {
  ck_assert_ldouble_infinite(powl(-0.1234, -S21_INFINITY));
  ck_assert_ldouble_infinite(s21_pow(-0.1234, -S21_INFINITY));
}
END_TEST

START_TEST(s10) {
  ck_assert_ldouble_eq_tol(powl(1234, -S21_INFINITY),
                           s21_pow(1234, -S21_INFINITY), 1e-7);
}
END_TEST

START_TEST(one_odd) {
  ck_assert_ldouble_eq_tol(powl(1, S21_M_PI), s21_pow(1, S21_M_PI), 1e-7);
}
END_TEST

START_TEST(minus_one_odd) {
  ck_assert_ldouble_nan(powl(-1, 3.14));
  ck_assert_ldouble_nan(s21_pow(-1, 3.14));
}
END_TEST

START_TEST(one_even) {
  ck_assert_ldouble_eq_tol(powl(1, 24), s21_pow(1, 24), 1e-7);
}
END_TEST

START_TEST(minus_one_even) {
  ck_assert_ldouble_eq_tol(powl(-1, 24), s21_pow(-1, 24), 1e-7);
}
END_TEST

START_TEST(powt) {
  double x = 5.4;
  for (int i = 0; i < 5; i++) {
    ck_assert_ldouble_eq_tol(powl(x, x - 2), s21_pow(x, x - 2), 1e-7);
    x++;
  }
}
END_TEST

START_TEST(man_1) {
  ck_assert_ldouble_infinite(pow(+0, -0.67));
  ck_assert_ldouble_infinite(s21_pow(+0, -0.67));
}
END_TEST

START_TEST(man_1_2) {
  ck_assert_ldouble_infinite(pow(-0, -0.67));
  ck_assert_ldouble_infinite(s21_pow(-0, -0.67));
}
END_TEST

START_TEST(man_2) {
  ck_assert_ldouble_eq_tol(pow(-0, 6), s21_pow(-0, 6), 1e-7);
}
END_TEST

START_TEST(man_3) {
  ck_assert_ldouble_infinite(pow(0.7, -INFINITY));
  ck_assert_ldouble_infinite(s21_pow(0.7, -INFINITY));
}
END_TEST

START_TEST(man_4) {
  ck_assert_ldouble_eq_tol(pow(33, -INFINITY), s21_pow(33, -INFINITY), 1e-7);
}
END_TEST

START_TEST(man_5) {
  ck_assert_ldouble_eq_tol(pow(0.33, +INFINITY), s21_pow(0.33, +INFINITY),
                           1e-7);
}
END_TEST

START_TEST(man_6) {
  ck_assert_ldouble_infinite(pow(-INFINITY, 45));
  ck_assert_ldouble_infinite(s21_pow(-INFINITY, 45));
}
END_TEST

START_TEST(man_7) {
  ck_assert_ldouble_eq_tol(pow(-INFINITY, -98), s21_pow(-INFINITY, -98), 1e-7);
  // ck_assert_ldouble_infinite(pow(-INFINITY, -98));
  // ck_assert_ldouble_infinite(s21_pow(-INFINITY, -98));
}
END_TEST

START_TEST(man_8) {
  ck_assert_ldouble_infinite(pow(-INFINITY, 81));
  ck_assert_ldouble_infinite(s21_pow(-INFINITY, 81));
}
END_TEST

START_TEST(man_9) {
  ck_assert_ldouble_infinite(pow(-INFINITY, 40));
  ck_assert_ldouble_infinite(s21_pow(-INFINITY, 40));
}
END_TEST

START_TEST(man_10) {
  ck_assert_ldouble_eq_tol(pow(INFINITY, -4), s21_pow(INFINITY, -4), 1e-7);
  // ck_assert_ldouble_infinite(pow(INFINITY, -4));
  // ck_assert_ldouble_infinite(s21_pow(INFINITY, -4));
}
END_TEST

START_TEST(man_11) {
  ck_assert_ldouble_eq_tol(pow(-INFINITY, -99), s21_pow(-INFINITY, -99), 1e-7);
}
END_TEST

//  pow(+infinity, y) returns +infinity for y > 0.
Suite *suite_s21_pow() {
  Suite *s = suite_create("s21_pow");
  TCase *temp = tcase_create("test_pow");
  suite_add_tcase(s, temp);

  tcase_add_test(temp, simple);

  // tcase_add_test(temp, s1);
  tcase_add_test(temp, s2);
  tcase_add_test(temp, s3);
  tcase_add_test(temp, s4);
  tcase_add_test(temp, s5);
  tcase_add_test(temp, s6);
  tcase_add_test(temp, s7);
  tcase_add_test(temp, s8);
  tcase_add_test(temp, s9);
  tcase_add_test(temp, s10);
  tcase_add_test(temp, powt);

  tcase_add_test(temp, one_odd);
  tcase_add_test(temp, minus_one_odd);

  tcase_add_test(temp, one_even);
  tcase_add_test(temp, minus_one_even);

  tcase_add_test(temp, man_1);
  tcase_add_test(temp, man_1_2);
  tcase_add_test(temp, man_2);
  tcase_add_test(temp, man_3);
  tcase_add_test(temp, man_4);
  tcase_add_test(temp, man_5);
  tcase_add_test(temp, man_6);
  tcase_add_test(temp, man_7);
  tcase_add_test(temp, man_8);
  tcase_add_test(temp, man_9);
  tcase_add_test(temp, man_10);
  tcase_add_test(temp, man_11);
  return s;
}