#pragma once

using ull = uint64_t;
constexpr ull HMOD = ull(-1) >> 3; // 2^61-1

ull hadd(ull a, ull b) {
	return (a += b) >= HMOD ? a-HMOD : a;
}
ull hmul(ull a, ull b) {
	auto t = __uint128_t(a) * b;
	return hadd(t >> 61, t & HMOD);
}

constexpr ull C = 0x314159265;

struct RollingHash {
	vector<ull> ha, pw;
	RollingHash(auto&& s, int n) : ha(n+1), pw(n+1) {
		pw[0] = 1;
		rep(i,n) {
			ha[i+1] = ha[i] * C + s[i],
			pw[i+1] = pw[i] * C;
		}
	}
	ull hash(int a, int b) {
		return ha[b] - ha[a] * pw[b-a];
	}
};
