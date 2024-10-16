/**
 * Author: Masato Shinokawa
 * Description: Segment tree with lazy propagation
 */

#pragma once


template <size_t N>
struct lazy_segtree {
	// range add, range max
	using T = int;
	using A = int;
	static constexpr T Tinit = INT_MIN;
	static constexpr A Ainit = 0;
	static constexpr int n = bit_ceil(N);
	T val[n*2];
	A laz[n*2];
	lazy_segtree() { fill(val, val+n, Tinit), fill(laz, laz+n, Ainit); }
	void apply(int i, A a) {
		val[i] += a;  // apply
		laz[i] += a;  // A op
	}
	void push(int i) {
		if (laz[i] == 0) return;
		apply(i*2, laz[i]);
		apply(i*2+1, laz[i]);
		laz[i] = 0;
	}
	void apply(int l, int r, A a, int i = 1, int L = 0, int R = n) {
		if (r <= L || R <= l) return;
		if (l <= L && R <= r) return apply(i, a);
		push(i);
		int M = (L + R) / 2;
		apply(l, r, a, i*2, L, M);
		apply(l, r, a, i*2+1, M, R);
		val[i] = max(val[i*2], val[i*2+1]);  // T op
	}
	T prod(int l, int r, int i = 1, int L = 0, int R = n) {
		if (r <= L || R <= l) return Tinit;
		if (l <= L && R <= r) return val[i];
		push(i);
		int M = (L + R) / 2;
		return max(prod(l, r, i*2, L, M), prod(l, r, i*2+1, M, R));  // T op
	}
};
