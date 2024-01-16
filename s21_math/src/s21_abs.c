#include "s21_math.h"

int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_fabs(double x) {
  long double result = 0;
  if (s21_is_nan(x))
    result = S21_NAN;
  else if (s21_is_inf(x))
    result = S21_INF;
  else
    result = (long double)x < EPS ? (x *= -1) : x;
  return result;
}