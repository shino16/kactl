/**
 * Author: Masato Shinokawa
 * Description: Arithmetic operations that clamp the results into the range that the type can represent. You can use INT\_MIN/INT\_MAX, LLONG\_MIN/LLONG\_MAX in place of numeric\_limits<T>::min()/max().
 */

template <class T>
auto sat_add(T a, T b) {
  T res;
  return __builtin_add_overflow(a, b, &res)
             ? (a < 0 ? numeric_limits<T>::min() : numeric_limits<T>::max())
             : res;
}

template <class T>
auto sat_sub(T a, T b) {
  T res;
  return __builtin_sub_overflow(a, b, &res)
             ? (a < 0 ? numeric_limits<T>::min() : numeric_limits<T>::max())
             : res;
}
template <class T>
auto sat_mul(T a, T b) {
  T res;
  return __builtin_mul_overflow(a, b, &res)
             ? ((a < 0) == (b < 0) ? numeric_limits<T>::max()
                                   : numeric_limits<T>::min())
             : res;
}
