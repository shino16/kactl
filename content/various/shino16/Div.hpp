/**
 * Author: Masato Shinokawa
 * Description: Division with rounding towards -inf (floor) or inf (ceil).
 */

int div_floor(int a, int b) {
  int q = a / b, r = a % b;
  return q - ((r > 0 && b < 0) || (r < 0 && b > 0));
}
int div_ceil(int a, int b) {
  int q = a / b, r = a % b;
  return q + ((r > 0 && b > 0) || (r < 0 && b < 0));
}
int rem(int a, int b){ return (a %= b) >= 0 ? a : a + abs(b); }
