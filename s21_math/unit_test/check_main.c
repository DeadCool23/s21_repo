#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "check_abs.h"
#include "check_degree.h"
#include "check_round.h"
#include "check_trigonometry.h"

typedef Suite *(*test_case_t)(void);

int main(void) {
  SRunner *runner;
  test_case_t unit_tests[] = {s21_abs_tests,  s21_fabs_tests, s21_exp_tests,
                              s21_log_tests,  s21_sqrt_tests, s21_pow_tests,
                              s21_tan_tests,  s21_sin_tests,  s21_cos_tests,
                              s21_atan_tests, s21_asin_tests, s21_acos_tests,
                              s21_ceil_tests, s21_floor_tests};
  size_t tests_cnt = sizeof(unit_tests) / sizeof(*unit_tests);

  int number_failed = 0;

  for (size_t i = 0; i < tests_cnt; i++) {
    puts("\n");
    runner = srunner_create(unit_tests[i]());
    srunner_run_all(runner, CK_NORMAL);
    number_failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}