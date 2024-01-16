#include "check_abs.h"

#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

// Позитивное число
START_TEST(pos) { ck_assert_int_eq(s21_abs(1), abs(1)); }
END_TEST

// Негативное число
START_TEST(neg) { ck_assert_int_eq(s21_abs(-1), abs(-1)); }
END_TEST

// Ноль
START_TEST(zero) { ck_assert_int_eq(s21_abs(0), abs(0)); }
END_TEST

Suite *s21_abs_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nabs");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, pos);
  tcase_add_test(tests, neg);
  tcase_add_test(tests, zero);

  suite_add_tcase(s, tests);

  return s;
}

// Позитивное число
START_TEST(fpos) { ck_assert_ldouble_eq(s21_fabs(1.0), fabs(1.0)); }
END_TEST

// Негативное число
START_TEST(fneg) { ck_assert_ldouble_eq(s21_fabs(-1.0), fabs(-1.0)); }
END_TEST

// Ноль
START_TEST(fzero) { ck_assert_ldouble_eq(s21_fabs(0.), fabs(0.)); }
END_TEST

// Негативный ноль
START_TEST(fnzero) {
  ck_assert_ldouble_eq(s21_fabs(S21_NEGZERO), fabs(S21_NEGZERO));
}
END_TEST

// Бесконечность
START_TEST(finf) { ck_assert_ldouble_eq(s21_fabs(S21_INF), fabs(S21_INF)); }
END_TEST

// Негативная Бесконечность
START_TEST(fninf) { ck_assert_ldouble_eq(s21_fabs(-S21_INF), fabs(-S21_INF)); }
END_TEST

// Not a number
START_TEST(fnan) { ck_assert_ldouble_nan(s21_fabs(S21_NAN)); }
END_TEST

Suite *s21_fabs_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nfabs");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, fpos);
  tcase_add_test(tests, fneg);
  tcase_add_test(tests, fzero);
  tcase_add_test(tests, fnzero);
  tcase_add_test(tests, finf);
  tcase_add_test(tests, fninf);
  tcase_add_test(tests, fnan);

  suite_add_tcase(s, tests);

  return s;
}