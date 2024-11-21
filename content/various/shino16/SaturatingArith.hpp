/**
 * Author: Masato Shinokawa
 * Description: Arithmetic operations that clamp the results into
 * the range that the type can represent. Use LLONG\_MIN/LLONG\_MAX for long longs.
 */

auto sat_[add|sub|mul](int a, int b) {
  int res;
  return __builtin_[add|sub|mul]_overflow(a, b, &res) ?
    (a<0 ? INT_MIN : INT_MAX) : res; // (a<0) != (b<0) for mul
}
