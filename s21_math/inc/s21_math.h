#ifndef S21_MATH_H_
#define S21_MATH_H_

#define S21_PI 3.14159265358979323846
#define S21_PI_2 (S21_PI / 2.F)
#define S21_PI_4 (S21_PI / 4.F)
#define S21_PI_4 (S21_PI / 4.F)
#define S21_1_PI (1.F / S21_PI)
#define S21_2_PI (2.F / S21_PI)

#define S21_E 2.71828182845904523536
#define S21_LN2 0.693147180559945309417
#define S21_LN10 2.30258509299404590109

#define S21_NEGZERO (-0.0)

#define S21_INF __builtin_inf()
#define S21_NAN __builtin_nan("NaN")

#define s21_is_inf __builtin_isinf
#define s21_is_nan __builtin_isnan

#define EPS 1e-7

/**
 * @brief Функция вычисляет абсолютное значение целого числа
 *
 * @param x - целое число
 * @return абсолютное значение
 */
int s21_abs(int x);

/**
 * @brief Функция вычисляет абсолютное значение числа с плавающей точкой
 *
 * @param x - вещественное число
 * @return абсолютное значение
 */
long double s21_fabs(double x);

/**
 * @brief Функция возвращает ближайшее целое число, не меньшее заданного
 * значения
 *
 * @param x - вещественное число
 * @return искомое число
 */
long double s21_ceil(double x);

/**
 * @brief Функция возвращает ближайшее целое число, не превышающее заданное
 * значение
 *
 * @param x - вещественное число
 * @return искомое число
 */
long double s21_floor(double x);

/**
 * @brief Функция вычисления значения арккосинуса
 *
 * @param x - вещественное число
 * @return значение арккосинуса
 */
long double s21_acos(double x);

/**
 * @brief Функция вычисления значения арксинуса
 *
 * @param x - вещественное число
 * @return значение арксинуса
 */
long double s21_asin(double x);

/**
 * @brief Функция вычисления значения арктангенса
 *
 * @param x - вещественное число
 * @return значение арктангенса
 */
long double s21_atan(double x);

/**
 * @brief Функция вычисления значения косинуса
 *
 * @param x - вещественное число
 * @return значение косинуса
 */
long double s21_cos(double x);

/**
 * @brief Функция вычисления значения синуса
 *
 * @param x - вещественное число
 * @return значение синуса
 */
long double s21_sin(double x);

/**
 * @brief Функция вычисления значения тангенса
 *
 * @param x - вещественное число
 * @return значение тангенса
 */
long double s21_tan(double x);

long double s21_exp(double x);

long double s21_log(double x);

long double s21_sqrt(double x);

long double s21_pow(double base, double exp);

long double s21_fmod(double x, double y);

#endif
