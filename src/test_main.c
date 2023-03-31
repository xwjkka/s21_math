#include <stdio.h>
#include <stdlib.h>

#include "tests/unit.h"

void run_test_case(Suite *testcase);
void run_all_tests();

int main() {
  run_all_tests();
  return 0;
}

void run_test_case(Suite *testcase) {
  static int count = 1;
  printf("TEST CASE №%d\n", count++);

  SRunner *sr;
  sr = srunner_create(testcase);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
}

void run_all_tests() {
  Suite *list_cases[] = {
      suite_s21_sin(),   suite_s21_pow(),  suite_s21_abs(),  suite_s21_fabs(),
      suite_s21_floor(), suite_s21_sqrt(), suite_s21_fmod(), suite_s21_exp(),
      suite_s21_log(),   suite_s21_cos(),  suite_s21_tan(),  suite_s21_asin(),
      suite_s21_acos(),  suite_s21_ceil(), suite_s21_atan(),
  };
  for (int i = 0; i < (int)(sizeof(list_cases) / sizeof(Suite *)); i++)
    run_test_case(list_cases[i]);
}