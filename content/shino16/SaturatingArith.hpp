/**
 * Author: Masato Shinokawa
 * Description: Arithmetic operations that clamp the results into
 * the range that the type can represent. Use LLONG\_MIN/LLONG\_MAX for long longs.
 */

auto sat_add(int a, int b) {
  int res;
  return __builtin_add_overflow(a, b, &res) ?
                      (a < 0 ? INT_MIN : INT_MAX) : res;
}
auto sat_sub(int a, int b) {
  int res;
  return __builtin_sub_overflow(a, b, &res) ?
                      (a < 0 ? INT_MIN : INT_MAX) : res;
}
auto sat_mul(int a, int b) {
  int res;
  return __builtin_mul_overflow(a, b, &res) ?
          ((a < 0) == (b < 0) ? INT_MAX : INT_MIN) : res;
}
