#include "s21_math.h"

int s21_isnan(double x) {
  int flag = 0;
  if (x != x) flag = 1;
  return flag;
}

long double s21_fmodl(long double x, long double delim) {
  long long temp = x / delim;
  long double res = 0;
  if (delim == 0 || x == +S21_INFINITY || x == -S21_INFINITY)
    res = S21_NAN;
  else if (delim == +S21_INFINITY || delim == -S21_INFINITY)
    res = x;
  else
    res = x - (delim * temp);
  return res;
}

int s21_abs(int x) { return x < 0 ? -x : x; }

long double s21_fabs(double x) { return x < 0 ? -x : x; }

long double s21_pow(double base, double exp) {
  long double res = 0;
  if (base == 1) {
    res = 1;
  } else if (base == -1) {
    if (s21_fmod(exp, 1) == 0) {
      res = s21_fmod(exp, 2) == 0 ? 1 : -1;
    } else {
      res = S21_NAN;
    }
  } else if (exp == 0) {
    res = 1;
  } else if (base == -S21_INFINITY) {
    if (exp < 0) {
      if (s21_fmod(exp, 1) == 0 && s21_fmod(exp, 2) != 0) {
        res = -0;
      } else if (s21_fmod(exp, 2) == 0) {
        res = +0;
      }
    } else {
      if (s21_fmod(exp, 1) == 0 && s21_fmod(exp, 2) != 0) {
        res = -S21_INFINITY;
      } else if (s21_fmod(exp, 2) == 0) {
        res = +S21_INFINITY;
      }
    }
  } else {
    if (exp == -S21_INFINITY && base > -1 && base < 1) {
      res = S21_INFINITY;
    } else {
      res = s21_exp(exp * s21_log(base));
    }
  }

  return res;
}

long double s21_exp(double x) {
  long double res = 1;
  int flag_m = 0;
  long double a = 1;
  if (x == S21_INFINITY || x > 709.782712893) {
    res = S21_INFINITY;
  } else if (x == -S21_INFINITY || x < -709.782712893) {
    res = 0;
  } else if (x == 0) {
    res = 1;
  } else if (x != 0) {
    if (x < 0) {
      x = s21_fabs(x);
      flag_m = 1;
    }

    for (double i = 1; a >= S21_EPS; i++) {
      a = a * (x / i);
      res += a;
    }
  }

  return flag_m ? (1 / res) : res;
}

long double s21_sqrt(double x) {
  long double res = 0;
  if (x == S21_INFINITY) {
    res = x;
  } else if (x == -S21_INFINITY || x != x || x < 0) {
    res = S21_NAN;
  } else {
    res = s21_pow(x, 0.5);
  }

  return res;
}

long double s21_fmod(double x, double y) {
  long long temp = x / y;
  long double res = 0;
  if (y == 0 || x == +S21_INFINITY || x == -S21_INFINITY)
    res = S21_NAN;
  else if (y == +S21_INFINITY || y == -S21_INFINITY)
    res = x;
  else
    res = x - (y * temp);
  return res;
}

long double s21_log(double x) {
  long double res = 0;
  if (x < 0 || x != x) {
    res = S21_NAN;
  } else if (x == 0) {
    res = -S21_INFINITY;
  } else if (S21_INFINITY == s21_fabs(x)) {
    res = x;
  } else {
    if (x > 0 && x < 2) {
      x -= 1;

      long double member = x, powX = x;
      int n = 1, sign = 1;
      while (s21_fabs(member) > S21_EPS) {
        res += member;
        sign = -sign;
        n++;
        powX *= x;
        member = (sign * powX) / n;
      }
    } else if (x >= 2 && x <= 10) {
      x = (x / (x - 1));
      for (int i = 1; i < NUM_OF_MEM; i++) {
        res += 1.0 / (i * s21_pow(x, i));
      }
    } else {
      int k = 0;
      if (x > 10) {
        while (x > 10) {
          x = x / 10;
          k++;
        }
      }
      res = s21_log(x) + (k * S21_LOG_10);
    }
  }
  return res;
}

long double s21_sin(double x) {
  long double temp_x = s21_fmodl(x, S21_M_PI * 2);
  long double step = temp_x, res = temp_x;
  int sign = -1, n = 1;
  long double fact = 1.L, step_makloren = 1.L;
  while (s21_fabs(step_makloren) >= S21_EPS) {
    fact = fact * (long double)(n + 1) * (long double)(n + 2);
    temp_x = temp_x * step * step;
    step_makloren = ((long double)sign * temp_x) / fact;
    res += step_makloren;
    n += 2, sign *= -1;
  }
  return res;
}

long double s21_floor(double x) {
  long double res = 0;
  if (s21_fabs(x) == S21_INFINITY) {
    res = x;
  } else if (s21_isnan(x)) {
    res = S21_NAN;
  } else {
    long long tmp = x / 1;
    long double ost = s21_fmod(x, 1);
    if (tmp <= 0 && ost && x <= 0) tmp -= 1;
    res = (long double)tmp;
  }
  return res;
}

long double s21_cos(double x) {
  long double step = s21_fmod(x, S21_M_PI * 2);
  ;
  long double temp_x = 1.L, res = 1.L;
  int sign = -1, n = 0;
  long double fact = 1.L, step_makloren = 1.L;
  while (s21_fabs(step_makloren) >= S21_EPS) {
    fact = fact * (long double)(n + 1) * (long double)(n + 2);
    temp_x = temp_x * step * step;
    step_makloren = ((long double)sign * temp_x) / fact;
    res += step_makloren;
    n += 2, sign *= -1;
  }
  return res;
}

long double s21_tan(double x) { return s21_sin(x) / s21_cos(x); }

long double s21_asin(double x) {
  long double step = x;
  long double temp_x = x, res = x;
  long double degree_x = 1, n = 2;
  long double delim = 1.L;
  long double div = 2.L;
  long double step_makloren = 1.L;
  if (s21_fabs(x) > 0.99l && s21_fabs(x) <= 1)
    res = s21_atan(x / s21_sqrt(1 - x * x));
  else {
    while (s21_fabs(step_makloren) >= S21_EPS) {
      temp_x = temp_x * step * step;
      degree_x += 2;
      step_makloren = (delim * temp_x) / (div * degree_x);
      res += step_makloren;
      n += 2;
      delim *= (long double)(n - 1);
      div *= (long double)n;
    }
  }
  return res;
}

long double s21_acos(double x) { return S21_M_PI_2 - s21_asin(x); }

long double s21_atan(double x) {
  int act = 0, step_count = 0;
  long double res = 0;
  if (s21_isnan(x)) res = S21_NAN;
  if (x < 0.L) {
    x = -x;
    act |= 1;
  }
  if (x > 1.L) {
    x = 1.L / x;
    act |= 2;
  }
  while (x > S21_M_PI12) {
    step_count++;
    res = x + S21_SQRT3;
    res = 1.L / res;
    x *= S21_SQRT3;
    x -= 1.L;
    x *= res;
  }
  res = x * (S21_TO_APR1 / (S21_TO_APR2 + x * x) + S21_TO_APR3 -
             S21_TO_APR4 * x * x);

  while (step_count > 0) {
    res += S21_M_PI6;
    step_count--;
  }
  if (act & 2) res = S21_M_PI_2 - res;
  if (act & 1) res = -res;
  return res;
}

long double s21_ceil(double x) {
  long double res = 0;
  if (s21_fabs(x) == S21_INFINITY) {
    res = x;
  } else if (s21_isnan(x)) {
    res = S21_NAN;
  } else {
    long long tmp = x / 1;
    long double ost = s21_fmod(x, 1);
    if (tmp >= 0 && ost && x >= 0) tmp += 1;
    res = (long double)tmp;
  }
  return res;
}