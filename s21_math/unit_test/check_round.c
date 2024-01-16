#include "check_round.h"

#include <math.h>

#include "s21_math.h"

// Целое положительное число
START_TEST(cpos_whole) { ck_assert_ldouble_eq(s21_ceil(1), ceil(1)); }
END_TEST

// Целое отрицательное число
START_TEST(cneg_whole) { ck_assert_ldouble_eq(s21_ceil(-1), ceil(-1)); }
END_TEST

// Дробное положительное число
START_TEST(cpos) { ck_assert_ldouble_eq(s21_ceil(1.1), ceil(1.1)); }
END_TEST

// Дробное отрицательное число
START_TEST(cneg) { ck_assert_ldouble_eq(s21_ceil(-1.1), ceil(-1.1)); }
END_TEST

// Ноль
START_TEST(czero) { ck_assert_ldouble_eq(s21_ceil(0), ceil(0)); }
END_TEST

// Минимальное число
START_TEST(cmin) { ck_assert_ldouble_eq(s21_ceil(DBL_MIN), ceil(DBL_MIN)); }
END_TEST

// Максимальное число
START_TEST(cmax) { ck_assert_ldouble_eq(s21_ceil(DBL_MAX), ceil(DBL_MAX)); }
END_TEST

// Бесконечность
START_TEST(cinf) { ck_assert_ldouble_eq(s21_ceil(S21_INF), ceil(S21_INF)); }
END_TEST

// Негативная бесконечность
START_TEST(cninf) { ck_assert_ldouble_eq(s21_ceil(-S21_INF), ceil(-S21_INF)); }
END_TEST

// Not a number
START_TEST(cnan) { ck_assert_ldouble_nan(s21_ceil(S21_NAN)); }
END_TEST

Suite *s21_ceil_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nceil");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, cpos_whole);
  tcase_add_test(tests, cneg_whole);
  tcase_add_test(tests, cpos);
  tcase_add_test(tests, cneg);
  tcase_add_test(tests, czero);
  tcase_add_test(tests, cmin);
  tcase_add_test(tests, cmax);
  tcase_add_test(tests, cinf);
  tcase_add_test(tests, cninf);
  tcase_add_test(tests, cnan);

  suite_add_tcase(s, tests);

  return s;
}

// Целое положительное число
START_TEST(fpos_whole) { ck_assert_ldouble_eq(s21_floor(1), floor(1)); }
END_TEST

// Целое отрицательное число
START_TEST(fneg_whole) { ck_assert_ldouble_eq(s21_floor(-1), floor(-1)); }
END_TEST

// Дробное положительное число
START_TEST(fpos) { ck_assert_ldouble_eq(s21_floor(1.1), floor(1.1)); }
END_TEST

// Дробное отрицательное число
START_TEST(fneg) { ck_assert_ldouble_eq(s21_floor(-1.1), floor(-1.1)); }
END_TEST

// Ноль
START_TEST(fzero) { ck_assert_ldouble_eq(s21_floor(0), floor(0)); }
END_TEST

// Минимальное число
START_TEST(flmin) { ck_assert_ldouble_eq(s21_floor(DBL_MIN), floor(DBL_MIN)); }
END_TEST

// Максимальное число
START_TEST(flmax) { ck_assert_ldouble_eq(s21_floor(DBL_MAX), floor(DBL_MAX)); }
END_TEST

// Бесконечность
START_TEST(finf) { ck_assert_ldouble_eq(s21_floor(S21_INF), floor(S21_INF)); }
END_TEST

// Негативная бесконечность
START_TEST(fninf) {
  ck_assert_ldouble_eq(s21_floor(-S21_INF), floor(-S21_INF));
}
END_TEST

// Not a number
START_TEST(fnan) { ck_assert_ldouble_nan(s21_floor(S21_NAN)); }
END_TEST

Suite *s21_floor_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nfloor");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, fpos_whole);
  tcase_add_test(tests, fneg_whole);
  tcase_add_test(tests, fpos);
  tcase_add_test(tests, fneg);
  tcase_add_test(tests, fzero);
  tcase_add_test(tests, flmin);
  tcase_add_test(tests, flmax);
  tcase_add_test(tests, finf);
  tcase_add_test(tests, fninf);
  tcase_add_test(tests, fnan);

  suite_add_tcase(s, tests);

  return s;
}