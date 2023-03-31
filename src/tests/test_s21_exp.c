#include "unit.h"

START_TEST(nll) { ck_assert_ldouble_eq_tol(exp(0), s21_exp(0), 1e-6); }
END_TEST

START_TEST(neg) { ck_assert_ldouble_eq_tol(exp(-800), s21_exp(-800), 1e-6); }
END_TEST

START_TEST(simple) { ck_assert_ldouble_eq_tol(exp(9), s21_exp(9), 1e-6); }
END_TEST

START_TEST(man_2) {
  ck_assert_ldouble_eq_tol(exp(-INFINITY), s21_exp(-INFINITY), 1e-6);
}
END_TEST

START_TEST(man_3) {
  ck_assert_ldouble_infinite(exp(INFINITY));
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
}
END_TEST

START_TEST(bb) {
  ck_assert_ldouble_infinite(exp(1000));
  ck_assert_ldouble_infinite(s21_exp(1000));
}
END_TEST

START_TEST(hardtest) {
  long double step = 0.143244;
  for (int i = 0; i < 10; i++) {
    step += step;
    ck_assert_ldouble_eq_tol(expl(i), s21_exp(i), 1e-6);
    step = -step;
  }
}
END_TEST

START_TEST(ultra_hard_test2) {
  ck_assert_ldouble_eq_tol(s21_exp(-171231.228941), expl(-171231.228941), 1e-6);
}
END_TEST

START_TEST(ultra_hard_test) {
  ck_assert_ldouble_infinite(s21_exp(709.8));
  ck_assert_ldouble_infinite(exp(709.8));
}
END_TEST

Suite *suite_s21_exp() {
  Suite *s = suite_create("s21_exp");
  TCase *temp = tcase_create("test_exp");
  suite_add_tcase(s, temp);
  tcase_add_test(temp, nll);
  tcase_add_test(temp, neg);
  tcase_add_test(temp, simple);

  tcase_add_test(temp, man_2);
  tcase_add_test(temp, man_3);

  tcase_add_test(temp, bb);
  tcase_add_test(temp, hardtest);
  tcase_add_test(temp, ultra_hard_test2);
  tcase_add_test(temp, ultra_hard_test);
  return s;
}