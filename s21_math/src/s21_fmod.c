#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long long mod = (long long)(x / y);
  long double res = (long double)x - mod * (long double)y;
  return res;
}