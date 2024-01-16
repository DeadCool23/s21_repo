#include <stdbool.h>
#include <stddef.h>

#include "s21_math.h"

long double s21_acos(double x) {
  long double asin_res = s21_asin(x);
  return S21_PI_2 - asin_res;
}

long double s21_asin(double x) {
  if (s21_fabs(x - 1) < EPS)
    return S21_PI_2;
  else if (s21_fabs(x + 1) < EPS)
    return -S21_PI_2;

  long double atan_res = s21_atan((double)(x / (s21_sqrt(1 - x * x))));
  return atan_res;
}

long double s21_atan(double x) {
  size_t step = 0;
  long double res = 0.0;
  long double step_res;
  bool flag = false;
  if (s21_is_nan(x)) return S21_NAN;
  if (s21_is_inf(x)) {
    if (x > 0)
      return S21_PI_2;
    else
      return -S21_PI_2;
  }
  // Если x больше по модулю, чем 1, то используем свойство симметрии
  if (s21_fabs(x) > 1) {
    x = 1 / x;
    flag = true;
  }
  /*
   * x > 1: res = pi / 2 - atan(1 / x)
   * x < -1: res = -pi / 2 + atan(1 / x)
   * иначе: res = atan(x)
   */
  step_res = x;
  while (step_res > EPS || step_res < -EPS) {
    res += step_res;
    step++;
    step_res = step_res * -1.0 * x * x * (2 * step - 1) / (2 * step + 1);
  }
  if (flag) {
    if (x > 0)
      res = S21_PI_2 - res;
    else
      res = -S21_PI_2 - res;
  }
  return res;
}

long double s21_cos(double x) {
  size_t step = 0;
  long double res = 0.0;
  long double step_res = 1;
  if (s21_is_nan(x)) return x;
  if (s21_is_inf(x)) return S21_NAN;

  x = x < 0 ? -x : x;  // Приводим косинус

  while (x > 2 * S21_PI) {
    x -= 2 * S21_PI;
  }
  // Считаем члены по формуле Тейлора
  while (step_res > EPS || step_res < -EPS) {
    res += step_res;
    step++;
    step_res = step_res * -1.0 * x * x / ((2.0 * step) * (2.0 * step - 1.0));
  }
  return res;
}

long double s21_sin(double x) {
  size_t step = 0;
  long double res = 0.0;
  long double step_res;
  if (s21_is_nan(x)) return x;
  if (s21_is_inf(x)) return S21_NAN;
  // Приводим синус
  while (x > 2 * S21_PI || x < -2 * S21_PI) {
    if (x > 2 * S21_PI)
      x -= 2 * S21_PI;
    else
      x += 2 * S21_PI;
  }
  step_res = x;
  // Считаем члены по формуле Тейлора
  while (step_res > EPS || step_res < -EPS) {
    res += step_res;
    step++;
    step_res = step_res * -1.0 * x * x / ((2.0 * step) * (2.0 * step + 1.0));
  }
  return res;
}

long double s21_tan(double x) {
  long double res_cos = s21_cos(x);
  long double res_sin = s21_sin(x);
  return res_sin / res_cos;
}
