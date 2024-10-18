/**
 * Author: Masato Shinokawa
 * Description: Xorshift64. Use this when you don't trust rand().
 */

uint64_t rand64() {
  static uint64_t x = 0x2002091620241018;
  x ^= x << 13;
	x ^= x >> 7;
	x ^= x << 17;
  return x;
}
