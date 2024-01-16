#include "check_trigonometry.h"

#include <check.h>
#include <math.h>

#include "s21_math.h"

// Тест нуля
START_TEST(first_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(second_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(third_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(40), tan(40), EPS);
}
END_TEST

// Тест большого положительного числа
START_TEST(fourth_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(1000), tan(1000), EPS);
}
END_TEST

// Тест маленького положительного числа
START_TEST(fifth_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(1e-5), tan(1e-5), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(sixth_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(seventh_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(-40), tan(-40), EPS);
}
END_TEST

// Тест большого отрицательного числа
START_TEST(eighth_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(-1000), tan(-1000), EPS);
}
END_TEST

// Тест маленького отрицательного числа
START_TEST(ninth_s21_tan_test) {
  ck_assert_ldouble_eq_tol(s21_tan(-1e-5), tan(-1e-5), EPS);
}
END_TEST

// Тест плюс бесконечности
START_TEST(tenth_s21_tan_test) { ck_assert_ldouble_nan(s21_tan(S21_INF)); }
END_TEST

// Тест минус бесконечности
START_TEST(eleventh_s21_tan_test) { ck_assert_ldouble_nan(s21_tan(-S21_INF)); }
END_TEST

// Тест nan
START_TEST(twelfth_s21_tan_test) { ck_assert_ldouble_nan(s21_tan(S21_NAN)); }
END_TEST

Suite *s21_tan_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\ntan");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_tan_test);
  tcase_add_test(tests, second_s21_tan_test);
  tcase_add_test(tests, third_s21_tan_test);
  tcase_add_test(tests, fourth_s21_tan_test);
  tcase_add_test(tests, fifth_s21_tan_test);
  tcase_add_test(tests, sixth_s21_tan_test);
  tcase_add_test(tests, seventh_s21_tan_test);
  tcase_add_test(tests, eighth_s21_tan_test);
  tcase_add_test(tests, ninth_s21_tan_test);
  tcase_add_test(tests, tenth_s21_tan_test);
  tcase_add_test(tests, eleventh_s21_tan_test);
  tcase_add_test(tests, twelfth_s21_tan_test);

  suite_add_tcase(s, tests);

  return s;
}

// Тест нуля
START_TEST(first_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(second_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(third_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(40), cos(40), EPS);
}
END_TEST

// Тест большого положительного числа
START_TEST(fourth_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(1000), cos(1000), EPS);
}
END_TEST

// Тест маленького положительного числа
START_TEST(fifth_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(1e-5), cos(1e-5), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(sixth_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(seventh_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(-40), cos(-40), EPS);
}
END_TEST

// Тест большого отрицательного числа
START_TEST(eighth_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(-1000), cos(-1000), EPS);
}
END_TEST

// Тест маленького отрицательного числа
START_TEST(ninth_s21_cos_test) {
  ck_assert_ldouble_eq_tol(s21_cos(-1e-5), cos(-1e-5), EPS);
}
END_TEST

// Тест плюс бесконечности
START_TEST(tenth_s21_cos_test) { ck_assert_ldouble_nan(s21_cos(S21_INF)); }
END_TEST

// Тест минус бесконечности
START_TEST(eleventh_s21_cos_test) { ck_assert_ldouble_nan(s21_cos(-S21_INF)); }
END_TEST

// Тест nan
START_TEST(twelfth_s21_cos_test) { ck_assert_ldouble_nan(s21_cos(S21_NAN)); }
END_TEST

Suite *s21_cos_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\ncos");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_cos_test);
  tcase_add_test(tests, second_s21_cos_test);
  tcase_add_test(tests, third_s21_cos_test);
  tcase_add_test(tests, fourth_s21_cos_test);
  tcase_add_test(tests, fifth_s21_cos_test);
  tcase_add_test(tests, sixth_s21_cos_test);
  tcase_add_test(tests, seventh_s21_cos_test);
  tcase_add_test(tests, eighth_s21_cos_test);
  tcase_add_test(tests, ninth_s21_cos_test);
  tcase_add_test(tests, tenth_s21_cos_test);
  tcase_add_test(tests, eleventh_s21_cos_test);
  tcase_add_test(tests, twelfth_s21_cos_test);

  suite_add_tcase(s, tests);

  return s;
}

// Тест нуля
START_TEST(first_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(second_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(third_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(40), sin(40), EPS);
}
END_TEST

// Тест большого положительного числа
START_TEST(fourth_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(1000), sin(1000), EPS);
}
END_TEST

// Тест маленького положительного числа
START_TEST(fifth_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(1e-5), sin(1e-5), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(sixth_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(seventh_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(-40), sin(-40), EPS);
}
END_TEST

// Тест большого отрицательного числа
START_TEST(eighth_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(-1000), sin(-1000), EPS);
}
END_TEST

// Тест маленького отрицательного числа
START_TEST(ninth_s21_sin_test) {
  ck_assert_ldouble_eq_tol(s21_sin(-1e-5), sin(-1e-5), EPS);
}
END_TEST

// Тест плюс бесконечности
START_TEST(tenth_s21_sin_test) { ck_assert_ldouble_nan(s21_sin(S21_INF)); }
END_TEST

// Тест минус бесконечности
START_TEST(eleventh_s21_sin_test) { ck_assert_ldouble_nan(s21_sin(-S21_INF)); }
END_TEST

// Тест nan
START_TEST(twelfth_s21_sin_test) { ck_assert_ldouble_nan(s21_sin(S21_NAN)); }
END_TEST

Suite *s21_sin_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nsin");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_sin_test);
  tcase_add_test(tests, second_s21_sin_test);
  tcase_add_test(tests, third_s21_sin_test);
  tcase_add_test(tests, fourth_s21_sin_test);
  tcase_add_test(tests, fifth_s21_sin_test);
  tcase_add_test(tests, sixth_s21_sin_test);
  tcase_add_test(tests, seventh_s21_sin_test);
  tcase_add_test(tests, eighth_s21_sin_test);
  tcase_add_test(tests, ninth_s21_sin_test);
  tcase_add_test(tests, tenth_s21_sin_test);
  tcase_add_test(tests, eleventh_s21_sin_test);
  tcase_add_test(tests, twelfth_s21_sin_test);

  suite_add_tcase(s, tests);

  return s;
}

// Тест нуля
START_TEST(first_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(0), atan(0), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(second_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(third_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(40), atan(40), EPS);
}
END_TEST

// Тест большого положительного числа
START_TEST(fourth_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(1000), atan(1000), EPS);
}
END_TEST

// Тест маленького положительного числа
START_TEST(fifth_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(1e-5), atan(1e-5), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(sixth_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(seventh_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(-40), atan(-40), EPS);
}
END_TEST

// Тест большого отрицательного числа
START_TEST(eighth_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(-1000), atan(-1000), EPS);
}
END_TEST

// Тест маленького отрицательного числа
START_TEST(ninth_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(-1e-5), atan(-1e-5), EPS);
}
END_TEST

// Тест плюс бесконечности
START_TEST(tenth_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(S21_INF), EPS);
}
END_TEST

// Тест минус бесконечности
START_TEST(eleventh_s21_atan_test) {
  ck_assert_ldouble_eq_tol(s21_atan(-S21_INF), atan(-S21_INF), EPS);
}
END_TEST

// Тест nan
START_TEST(twelfth_s21_atan_test) { ck_assert_ldouble_nan(s21_atan(S21_NAN)); }
END_TEST

Suite *s21_atan_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\natan");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_atan_test);
  tcase_add_test(tests, second_s21_atan_test);
  tcase_add_test(tests, third_s21_atan_test);
  tcase_add_test(tests, fourth_s21_atan_test);
  tcase_add_test(tests, fifth_s21_atan_test);
  tcase_add_test(tests, sixth_s21_atan_test);
  tcase_add_test(tests, seventh_s21_atan_test);
  tcase_add_test(tests, eighth_s21_atan_test);
  tcase_add_test(tests, ninth_s21_atan_test);
  tcase_add_test(tests, tenth_s21_atan_test);
  tcase_add_test(tests, eleventh_s21_atan_test);
  tcase_add_test(tests, twelfth_s21_atan_test);

  suite_add_tcase(s, tests);

  return s;
}

// Тест нуля
START_TEST(first_s21_asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(second_s21_asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), EPS);
}
END_TEST

// Тест положительного числа за ОДС
START_TEST(third_s21_asin_test) { ck_assert_ldouble_nan(s21_asin(40)); }
END_TEST

// Тест маленького положительного числа
START_TEST(fourth_s21_asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(1e-5), asin(1e-5), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(fifth_s21_asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(-1), asin(-1), EPS);
}
END_TEST

// Тест отрицательного числа за ОДС
START_TEST(sixth_s21_asin_test) { ck_assert_ldouble_nan(s21_asin(-40)); }
END_TEST

// Тест маленького отрицательного числа
START_TEST(seventh_s21_asin_test) {
  ck_assert_ldouble_eq_tol(s21_asin(-1e-5), asin(-1e-5), EPS);
}
END_TEST

// Тест плюс бесконечности
START_TEST(eighth_s21_asin_test) { ck_assert_ldouble_nan(s21_asin(S21_INF)); }
END_TEST

// Тест минус бесконечности
START_TEST(ninth_s21_asin_test) { ck_assert_ldouble_nan(s21_asin(S21_INF)); }
END_TEST

// Тест nan
START_TEST(tenth_s21_asin_test) { ck_assert_ldouble_nan(s21_asin(S21_INF)); }
END_TEST

Suite *s21_asin_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nasin");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_asin_test);
  tcase_add_test(tests, second_s21_asin_test);
  tcase_add_test(tests, third_s21_asin_test);
  tcase_add_test(tests, fourth_s21_asin_test);
  tcase_add_test(tests, fifth_s21_asin_test);
  tcase_add_test(tests, sixth_s21_asin_test);
  tcase_add_test(tests, seventh_s21_asin_test);
  tcase_add_test(tests, eighth_s21_asin_test);
  tcase_add_test(tests, ninth_s21_asin_test);
  tcase_add_test(tests, tenth_s21_asin_test);

  suite_add_tcase(s, tests);

  return s;
}

// Тест нуля
START_TEST(first_s21_acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), EPS);
}
END_TEST

// Тест положительного числа
START_TEST(second_s21_acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), EPS);
}
END_TEST

// Тест положительного числа за ОДС
START_TEST(third_s21_acos_test) { ck_assert_ldouble_nan(s21_acos(40)); }
END_TEST

// Тест маленького положительного числа
START_TEST(fourth_s21_acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(1e-5), acos(1e-5), EPS);
}
END_TEST

// Тест отрицательного числа
START_TEST(fifth_s21_acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), EPS);
}
END_TEST

// Тест отрицательного числа за ОДС
START_TEST(sixth_s21_acos_test) { ck_assert_ldouble_nan(s21_acos(-40)); }
END_TEST

// Тест маленького отрицательного числа
START_TEST(seventh_s21_acos_test) {
  ck_assert_ldouble_eq_tol(s21_acos(-1e-5), acos(-1e-5), EPS);
}
END_TEST

// Тест плюс бесконечности
START_TEST(eighth_s21_acos_test) { ck_assert_ldouble_nan(s21_acos(S21_INF)); }
END_TEST

// Тест минус бесконечности
START_TEST(ninth_s21_acos_test) { ck_assert_ldouble_nan(s21_acos(S21_INF)); }
END_TEST

// Тест nan
START_TEST(tenth_s21_acos_test) { ck_assert_ldouble_nan(s21_acos(S21_INF)); }
END_TEST

Suite *s21_acos_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nacos");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_acos_test);
  tcase_add_test(tests, second_s21_acos_test);
  tcase_add_test(tests, third_s21_acos_test);
  tcase_add_test(tests, fourth_s21_acos_test);
  tcase_add_test(tests, fifth_s21_acos_test);
  tcase_add_test(tests, sixth_s21_acos_test);
  tcase_add_test(tests, seventh_s21_acos_test);
  tcase_add_test(tests, eighth_s21_acos_test);
  tcase_add_test(tests, ninth_s21_acos_test);
  tcase_add_test(tests, tenth_s21_acos_test);

  suite_add_tcase(s, tests);

  return s;
}