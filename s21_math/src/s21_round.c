#include <float.h>

#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = (long long int)x;
  if (x >= DBL_MIN && x <= DBL_MIN) {
    res = 1;
  } else if (s21_is_inf(x) || s21_fabs(x) < EPS || s21_is_nan(x) ||
             s21_fabs(x - DBL_MAX) < EPS) {
    res = x;
  } else {
    if (s21_fabs(x) > 0. && s21_fabs((double)(x - res)) > EPS)
      if (x > 0.) res += 1;
  }
  return res;
}

long double s21_floor(double x) {
  long double res = (long long int)x;
  if (x >= DBL_MIN && x <= DBL_MIN) {
    res = 0;
  } else if (s21_is_inf(x) || s21_fabs(x) < EPS || s21_is_nan(x) ||
             s21_fabs(x - DBL_MAX) < EPS) {
    res = x;
  } else {
    if (s21_fabs((double)(x - res)) > 0. && s21_fabs(x) > 0.)
      if (x < 0.) res -= 1;
  }
  return res;
}
