#include "unit.h"

START_TEST(simple) {
  ck_assert_ldouble_nan(s21_fmod(0, 0));
  ck_assert_ldouble_nan(fmodl(0, 0));
}
END_TEST

START_TEST(simple2) {
  ck_assert_ldouble_eq_tol(s21_fmod(0, 2), fmodl(0, 2), 1e-6);
}
END_TEST

START_TEST(hard) {
  ck_assert_ldouble_eq_tol(s21_fmod(123845013.15, 12231.21),
                           fmodl(123845013.15, 12231.21), 1e-6);
}
END_TEST

START_TEST(hard2) {
  ck_assert_ldouble_eq_tol(s21_fmod(-1845013.15315, -717.2931),
                           fmodl(-1845013.15315, -717.2931), 1e-6);
}
END_TEST

START_TEST(if_nan1) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 17.25));
  ck_assert_ldouble_nan(fmodl(NAN, 17.25));
}
END_TEST

START_TEST(if_nan2) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, S21_NAN));
  ck_assert_ldouble_nan(fmodl(NAN, NAN));
}
END_TEST

START_TEST(if_nan3) {
  ck_assert_ldouble_nan(s21_fmod(1512321.124, S21_NAN));
  ck_assert_ldouble_nan(fmodl(1512321.124, S21_NAN));
}
END_TEST

START_TEST(if_inf1) {
  ck_assert_ldouble_nan(s21_fmod(+S21_INFINITY, 16123.125));
  ck_assert_ldouble_nan(fmodl(+INFINITY, 16123.125));
}
END_TEST

START_TEST(if_inf2) {
  ck_assert_ldouble_nan(s21_fmod(S21_INFINITY, S21_INFINITY));
  ck_assert_ldouble_nan(fmodl(-S21_INFINITY, S21_INFINITY));
}
END_TEST

START_TEST(if_inf3) {
  ck_assert_ldouble_eq_tol(s21_fmod(9821.123, S21_INFINITY),
                           fmodl(9821.123, S21_INFINITY), 1e-6);
}
END_TEST

START_TEST(negative1) {
  ck_assert_ldouble_eq_tol(s21_fmod(21421.12412, -214.15),
                           fmodl(21421.12412, -214.15), 1e-6);
}
END_TEST

START_TEST(negative2) {
  ck_assert_ldouble_eq_tol(s21_fmod(1, -0.51), fmodl(1, -0.51), 1e-6);
}
END_TEST

START_TEST(negative3) {
  ck_assert_ldouble_eq_tol(s21_fmod(-1274821.5, 23.33),
                           fmodl(-1274821.5, 23.33), 1e-6);
}
END_TEST

Suite *suite_s21_fmod() {
  Suite *s = suite_create("s21_fmod");
  TCase *temp = tcase_create("test_fmod");
  suite_add_tcase(s, temp);

  tcase_add_test(temp, simple);
  tcase_add_test(temp, simple2);
  tcase_add_test(temp, hard);
  tcase_add_test(temp, hard2);
  tcase_add_test(temp, if_nan1);
  tcase_add_test(temp, if_nan2);
  tcase_add_test(temp, if_nan3);
  tcase_add_test(temp, if_inf1);
  tcase_add_test(temp, if_inf2);
  tcase_add_test(temp, if_inf3);
  tcase_add_test(temp, negative1);
  tcase_add_test(temp, negative2);
  tcase_add_test(temp, negative3);

  return s;
}