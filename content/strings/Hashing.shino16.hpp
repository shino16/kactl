/**
 * Author: Masato Shinokawa
 * Description: Rolling Hash with mod $2^{61} - 1$
 */


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

constexpr ull R = 0x314159265;

struct RollingHash {
	vector<ull> ha, pw;
	RollingHash(auto&& s, int n) : ha(n+1), pw(n+1) {
		pw[0] = 1;
		rep(i,0,n) {
			ha[i+1] = hadd(hmul(ha[i], R), s[i]);
			pw[i+1] = hmul(pw[i], R);
		}
	}
	ull hash(int a, int b) {
		return hadd(ha[b], HMOD - hmul(ha[a], pw[b-a]));
	}
};
