#include "unit.h"

START_TEST(abst) {
  int x = 3273489729;
  while (x > 0) {
    ck_assert_int_eq(abs(x), s21_abs(x));
    x = -x;
    ck_assert_int_eq(abs(x), s21_abs(x));
    x /= 2;
  }
  ck_assert_int_eq(abs(x), s21_abs(x));
}
END_TEST

START_TEST(simple) { ck_assert_int_eq(s21_abs(1), abs(1)); }
END_TEST

START_TEST(simple2) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

START_TEST(simple3) { ck_assert_int_eq(s21_abs(-2), abs(-2)); }
END_TEST

START_TEST(simple4) { ck_assert_int_eq(s21_abs(123213124), abs(123213124)); }
END_TEST

START_TEST(simple5) { ck_assert_int_eq(s21_abs(-324234324), abs(-324234324)); }
END_TEST

Suite *suite_s21_abs() {
  Suite *s = suite_create("s21_abs");
  TCase *temp = tcase_create("test_abs");

  suite_add_tcase(s, temp);

  tcase_add_test(temp, abst);
  tcase_add_test(temp, simple);
  tcase_add_test(temp, simple2);
  tcase_add_test(temp, simple3);
  tcase_add_test(temp, simple4);
  tcase_add_test(temp, simple5);

  return s;
}