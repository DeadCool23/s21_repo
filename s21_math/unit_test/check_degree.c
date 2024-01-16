#include "check_degree.h"

#include <check.h>
#include <math.h>

#include "s21_math.h"

// Возведение в ноль
START_TEST(first_s21_exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), EPS);
}
END_TEST

// Возведение в положительную степень
START_TEST(second_s21_exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(10), exp(10), EPS);
}
END_TEST

// Возведение в большую степень
START_TEST(third_s21_exp_test) {
  ck_assert_ldouble_eq(s21_exp(1000), exp(1000));
}
END_TEST

// Возведение в маленькую положительную степень
START_TEST(fourth_s21_exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(1e-5), exp(1e-5), EPS);
}
END_TEST

// Возведение в отрицательную степень
START_TEST(fifth_s21_exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(-1), exp(-1), EPS);
}
END_TEST

// Возведение в большую отрицательную степень
START_TEST(sixth_s21_exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(-1000), exp(-1000), EPS);
}
END_TEST

// Возведение в маленькую отрицательную степень
START_TEST(seventh_s21_exp_test) {
  ck_assert_ldouble_eq_tol(s21_exp(-1e-5), exp(-1e-5), EPS);
}
END_TEST

// Возведение плюс бесконечность
START_TEST(eighth_s21_exp_test) {
  ck_assert_ldouble_eq(s21_exp(S21_INF), exp(S21_INF));
}
END_TEST

// Возведение минус бесконечность
START_TEST(ninth_s21_exp_test) {
  ck_assert_ldouble_eq(s21_exp(-S21_INF), exp(-S21_INF));
}
END_TEST

// Возведение в nan
START_TEST(tenth_s21_exp_test) { ck_assert_ldouble_nan(s21_exp(S21_NAN)); }
END_TEST

Suite *s21_exp_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nexp");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_exp_test);
  tcase_add_test(tests, second_s21_exp_test);
  tcase_add_test(tests, third_s21_exp_test);
  tcase_add_test(tests, fourth_s21_exp_test);
  tcase_add_test(tests, fifth_s21_exp_test);
  tcase_add_test(tests, sixth_s21_exp_test);
  tcase_add_test(tests, seventh_s21_exp_test);
  tcase_add_test(tests, eighth_s21_exp_test);
  tcase_add_test(tests, ninth_s21_exp_test);
  tcase_add_test(tests, tenth_s21_exp_test);

  suite_add_tcase(s, tests);

  return s;
}

// Логарифм нуля
START_TEST(first_s21_log_test) { ck_assert_ldouble_eq(s21_log(0), log(0)); }
END_TEST

// Логарифм положительного числа
START_TEST(second_s21_log_test) {
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), EPS);
}
END_TEST

// Логарифм отрицательного числа
START_TEST(third_s21_log_test) { ck_assert_ldouble_nan(s21_log(-1)); }
END_TEST

// Логарифм большого положительного числа
START_TEST(fourth_s21_log_test) {
  ck_assert_ldouble_eq_tol(s21_log(1000), log(1000), EPS);
}
END_TEST

// Логарифм маленького положительного числа
START_TEST(fifth_s21_log_test) {
  ck_assert_ldouble_eq_tol(s21_log(1e-5), log(1e-5), EPS);
}
END_TEST

// Логарифм плюс бесконечности
START_TEST(sixth_s21_log_test) {
  ck_assert_ldouble_eq(s21_log(S21_INF), log(S21_INF));
}
END_TEST

// Логарифм минус бесконечности
START_TEST(seventh_s21_log_test) { ck_assert_ldouble_nan(s21_log(-S21_INF)); }
END_TEST

// Логарифм nan
START_TEST(eighth_s21_log_test) { ck_assert_ldouble_nan(s21_log(S21_NAN)); }
END_TEST

Suite *s21_log_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nlog");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_log_test);
  tcase_add_test(tests, second_s21_log_test);
  tcase_add_test(tests, third_s21_log_test);
  tcase_add_test(tests, fourth_s21_log_test);
  tcase_add_test(tests, fifth_s21_log_test);
  tcase_add_test(tests, sixth_s21_log_test);
  tcase_add_test(tests, seventh_s21_log_test);
  tcase_add_test(tests, eighth_s21_log_test);

  suite_add_tcase(s, tests);

  return s;
}

// Корень положительного числа
START_TEST(first_s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(10), sqrt(10), EPS);
}
END_TEST

// Целый корень из нуля
START_TEST(second_s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), EPS);
}
END_TEST

// Корень из отрицательного числа
START_TEST(third_s21_sqrt_test) { ck_assert_ldouble_nan(s21_sqrt(-1)); }
END_TEST

// Корень из маленького положительного числа
START_TEST(fourth_s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), EPS);
}
END_TEST

START_TEST(fifth_s21_sqrt_test) {
  ck_assert_ldouble_eq_tol(s21_sqrt(1e-5), sqrt(1e-5), EPS);
}
END_TEST

// Корень из плюс бесконечности
START_TEST(sixth_s21_sqrt_test) {
  ck_assert_ldouble_eq(s21_sqrt(S21_INF), sqrt(S21_INF));
}
END_TEST

// Корень из минус бесконечности
START_TEST(seventh_s21_sqrt_test) { ck_assert_ldouble_nan(s21_sqrt(-S21_INF)); }
END_TEST

// Корень из nan
START_TEST(eighth_s21_sqrt_test) { ck_assert_ldouble_nan(s21_sqrt(S21_NAN)); }
END_TEST

Suite *s21_sqrt_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\nsqrt");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_sqrt_test);
  tcase_add_test(tests, second_s21_sqrt_test);
  tcase_add_test(tests, third_s21_sqrt_test);
  tcase_add_test(tests, fourth_s21_sqrt_test);
  tcase_add_test(tests, fifth_s21_sqrt_test);
  tcase_add_test(tests, sixth_s21_sqrt_test);
  tcase_add_test(tests, seventh_s21_sqrt_test);
  tcase_add_test(tests, eighth_s21_sqrt_test);

  suite_add_tcase(s, tests);

  return s;
}

// Положительное число в положительную целую степень
START_TEST(first_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 3), pow(2, 3), EPS);
}
END_TEST

// Положительное число в отрицательную целую степень
START_TEST(second_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(2, -3), pow(2, -3), EPS);
}
END_TEST

// Положительное число в положительную дробную степень
START_TEST(third_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(2, 2.5), pow(2, 2.5), EPS);
}
END_TEST

// Положительное число в отрицательную целую степень
START_TEST(fourth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(2, -3.5), pow(2, -3.5), EPS);
}
END_TEST

// Отрицательное число в четную положительную степень
START_TEST(fifth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-2, 4), pow(-2, 4), EPS);
}
END_TEST

// Отрицательное число в нечетную положительную степень
START_TEST(sixth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-2, 3), pow(-2, 3), EPS);
}
END_TEST

// Ноль в положительную степень
START_TEST(seventh_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 2), pow(0, 2), EPS);
}
END_TEST

// Ноль в отрицательную степень
START_TEST(eighth_s21_pow_test) {
  ck_assert_ldouble_eq(s21_pow(0, -2), pow(0, -2));
}
END_TEST

// Ноль в nan
START_TEST(ninth_s21_pow_test) { ck_assert_ldouble_nan(s21_pow(0, S21_NAN)); }
END_TEST

// Ноль в ноль
START_TEST(tenth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), EPS);
}
END_TEST

// Ноль в плюс бесконечность
START_TEST(eleventh_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(0, S21_INF), pow(0, S21_INF), EPS);
}
END_TEST

// Ноль в минус бесконечность
START_TEST(twelfth_s21_pow_test) {
  ck_assert_ldouble_eq(s21_pow(0, -S21_INF), pow(0, -S21_INF));
}
END_TEST

// Минус единица число в плюс бесконечность
START_TEST(thirteenth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, S21_INF), pow(-1, S21_INF), EPS);
}
END_TEST

// Минус единица число в минус бесконечность
START_TEST(fourteenth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-1, -S21_INF), pow(-1, -S21_INF), EPS);
}
END_TEST

// Единица число в ноль
START_TEST(fifteenth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 0), pow(1, 0), EPS);
}
END_TEST

// Единица число в nan
START_TEST(sixteenth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_NAN), pow(1, S21_NAN), EPS);
}
END_TEST

// Единица число в плюс бесконечность
START_TEST(seventeenth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_INF), pow(1, S21_INF), EPS);
}
END_TEST

// Единица число в минус бесконечность
START_TEST(eighteenth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(1, -S21_INF), pow(1, -S21_INF), EPS);
}
END_TEST

// nan в ноль
START_TEST(ninteenth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_NAN, 0), pow(S21_NAN, 0), EPS);
}
END_TEST

// nan в плюс бесконечность
START_TEST(twentieth_s21_pow_test) {
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_INF));
}
END_TEST

// nan в минус бесконечность
START_TEST(twenty_first_s21_pow_test) {
  ck_assert_ldouble_nan(s21_pow(S21_NAN, -S21_INF));
}
END_TEST

// nan в nan
START_TEST(twenty_second_s21_pow_test) {
  ck_assert_ldouble_nan(s21_pow(S21_NAN, S21_NAN));
}
END_TEST

// Положительное число в плюс бесконечности
START_TEST(twenty_third_s21_pow_test) {
  ck_assert_ldouble_eq(s21_pow(2, S21_INF), pow(2, S21_INF));
}
END_TEST

// Положительное число в минус бесконечности
START_TEST(twenty_fourth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(2, -S21_INF), pow(2, -S21_INF), EPS);
}
END_TEST

// Отрицательное число в плюс бесконечности
START_TEST(twenty_fifth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-2, -S21_INF), pow(-2, -S21_INF), EPS);
}
END_TEST

// Отрицательное число в минус бесконечности
START_TEST(twenty_sixth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-2, -S21_INF), pow(-2, -S21_INF), EPS);
}
END_TEST

// Плюс бесконечность в положительной степени
START_TEST(twenty_seventh_s21_pow_test) {
  ck_assert_ldouble_eq(s21_pow(S21_INF, 4), pow(S21_INF, 4));
}
END_TEST

// Плюс бесконечность в отрицательной степени
START_TEST(twenty_eight_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -4), pow(S21_INF, -4), EPS);
}
END_TEST

// Плюс бесконечность в плюс бесконечности
START_TEST(twenty_ninth_s21_pow_test) {
  ck_assert_ldouble_eq(s21_pow(S21_INF, S21_INF), pow(S21_INF, S21_INF));
}
END_TEST

// Плюс бесконечность в минус бесконечности
START_TEST(thirtieth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(S21_INF, -S21_INF), pow(S21_INF, -S21_INF),
                           EPS);
}
END_TEST

// Плюс бесконечность в nan
START_TEST(thirtieth_first_s21_pow_test) {
  ck_assert_ldouble_nan(s21_pow(S21_INF, S21_NAN));
}
END_TEST

// Минус бесконечность в положительной степени
START_TEST(thirtieth_second_s21_pow_test) {
  ck_assert_ldouble_eq(s21_pow(-S21_INF, 4), pow(-S21_INF, 4));
}
END_TEST

// Минус бесконечность в отрицательной степени
START_TEST(thirtieth_third_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, -4), pow(-S21_INF, -4), EPS);
}
END_TEST

// Минус бесконечность в плюс бесконечности
START_TEST(thirtieth_fourth_s21_pow_test) {
  ck_assert_ldouble_eq(s21_pow(-S21_INF, S21_INF), pow(-S21_INF, S21_INF));
}
END_TEST

// Минус бесконечность в минус бесконечности
START_TEST(thirtieth_fifth_s21_pow_test) {
  ck_assert_ldouble_eq_tol(s21_pow(-S21_INF, -S21_INF), pow(-S21_INF, -S21_INF),
                           EPS);
}
END_TEST

// Минус бесконечность в nan
START_TEST(thirtieth_sixth_s21_pow_test) {
  ck_assert_ldouble_nan(s21_pow(-S21_INF, S21_NAN));
}
END_TEST

Suite *s21_pow_tests(void) {
  Suite *s;
  TCase *tests;

  s = suite_create("\npow");
  tests = tcase_create(" tests ");

  tcase_add_test(tests, first_s21_pow_test);
  tcase_add_test(tests, second_s21_pow_test);
  tcase_add_test(tests, third_s21_pow_test);
  tcase_add_test(tests, fourth_s21_pow_test);
  tcase_add_test(tests, fifth_s21_pow_test);
  tcase_add_test(tests, sixth_s21_pow_test);
  tcase_add_test(tests, seventh_s21_pow_test);
  tcase_add_test(tests, eighth_s21_pow_test);
  tcase_add_test(tests, ninth_s21_pow_test);
  tcase_add_test(tests, tenth_s21_pow_test);
  tcase_add_test(tests, eleventh_s21_pow_test);
  tcase_add_test(tests, twelfth_s21_pow_test);
  tcase_add_test(tests, thirteenth_s21_pow_test);
  tcase_add_test(tests, fourteenth_s21_pow_test);
  tcase_add_test(tests, fifteenth_s21_pow_test);
  tcase_add_test(tests, sixteenth_s21_pow_test);
  tcase_add_test(tests, seventeenth_s21_pow_test);
  tcase_add_test(tests, eighteenth_s21_pow_test);
  tcase_add_test(tests, ninteenth_s21_pow_test);
  tcase_add_test(tests, twentieth_s21_pow_test);
  tcase_add_test(tests, twenty_first_s21_pow_test);
  tcase_add_test(tests, twenty_second_s21_pow_test);
  tcase_add_test(tests, twenty_third_s21_pow_test);
  tcase_add_test(tests, twenty_fourth_s21_pow_test);
  tcase_add_test(tests, twenty_fifth_s21_pow_test);
  tcase_add_test(tests, twenty_sixth_s21_pow_test);
  tcase_add_test(tests, twenty_seventh_s21_pow_test);
  tcase_add_test(tests, twenty_eight_s21_pow_test);
  tcase_add_test(tests, twenty_ninth_s21_pow_test);
  tcase_add_test(tests, thirtieth_s21_pow_test);
  tcase_add_test(tests, thirtieth_first_s21_pow_test);
  tcase_add_test(tests, thirtieth_second_s21_pow_test);
  tcase_add_test(tests, thirtieth_third_s21_pow_test);
  tcase_add_test(tests, thirtieth_fourth_s21_pow_test);
  tcase_add_test(tests, thirtieth_fifth_s21_pow_test);
  tcase_add_test(tests, thirtieth_sixth_s21_pow_test);

  suite_add_tcase(s, tests);

  return s;
}