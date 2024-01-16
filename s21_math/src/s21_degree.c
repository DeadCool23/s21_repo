#include <stddef.h>
#include <values.h>

#include "s21_math.h"

#define EPS_DIV_100000 (EPS / 100000)

long double s21_exp(double x) {
  size_t step = 0;
  long double res = 0.0;
  long double step_res;
  if ((s21_is_inf(x) && x < 0) || x < -14.5) return 0;
  if (s21_is_nan(x)) return x;
  step_res = 1;
  // Считаем члены по формуле Тейлора
  while (step_res > EPS_DIV_100000 || step_res < -EPS_DIV_100000) {
    res += step_res;
    step++;
    step_res = step_res * x / step;
    if (res > MAXDOUBLE) return S21_INF;
  }
  return res;
}

long double s21_log(double x) {
  long double z = (x - 1) / (x + 1);
  size_t step = 0;
  long double res = 0.0;
  long double step_res = z;
  // Краевые ситуации
  if (s21_is_nan(x) || x < 0) return S21_NAN;
  if (s21_is_inf(x)) return x;
  if (s21_fabs(x) < EPS) return -S21_INF;

  while (step_res > EPS_DIV_100000 || step_res < -EPS_DIV_100000) {
    res += step_res;
    step += 1;
    step_res = step_res * z * z * (2 * step - 1) / (2 * step + 1);
  }
  return 2 * res;
}

#undef EPS_DIV_100000

long double s21_sqrt(double x) {
  if (x < 0) return S21_NAN;
  if (s21_fabs(x) < EPS) return 0.0;
  if (s21_is_inf(x)) return x;

  long double x_prev = x / 2;
  // Итерационная формула Герона
  long double x_cur = 1.0 / 2.0 * (x_prev + x / x_prev);

  // s21_fabs не используется, чтобы не потерять точность
  long double delta = x_cur > x_prev ? x_cur - x_prev : x_prev - x_cur;
  while (delta > EPS) {
    x_prev = x_cur;
    x_cur = 1.0 / 2.0 * (x_prev + x / x_prev);
    // Последовательность убывает, начиная со второго элемента, поэтому
    // необходимость в модуле отпадает
    delta = x_prev - x_cur;
  }
  return x_cur;
}

long double s21_pow(double base, double exp) {
  long double res;
  if (s21_fabs(exp) < EPS) return 1;
  if (s21_fabs((double)(s21_fabs(base) - 1)) < EPS &&
      (s21_is_inf(exp) || s21_is_nan(exp)))
    return 1;
  if (s21_is_inf(base) && s21_is_inf(exp) && base < 0 && exp > 0)
    return S21_INF;
  if (base < 0) {
    base = -base;
    res = s21_exp((double)(exp * s21_log(base)));
    if (s21_fmod(exp, 2) > EPS) res = -res;
  } else {
    res = s21_exp((double)(exp * s21_log(base)));
  }
  return res;
}