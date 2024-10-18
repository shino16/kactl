/**
 * Author: Masato Shinokawa
 * Description: Division with rounding towards -inf (floor) or inf (ceil).
 */

template <class T>
T div_floor(T a, T b) {
  T q = a / b, r = a % b;
  return q - ((r > 0 && b < 0) || (r < 0 && b > 0));
}

template <class T>
T div_ceil(T a, T b) {
  T q = a / b, r = a % b;
  return q + ((r > 0 && b > 0) || (r < 0 && b < 0));
}

template <class T>
T rem(T a, T b) {
  T r = a % b;
  return r >= 0 ? r : r + abs(b);
}
