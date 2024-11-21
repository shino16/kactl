/**
 * Author: Masato Shinokawa
 * Source: https://q.c.titech.ac.jp/docs/progs/polynomial_division.html
 * Description: Computes $[x^n] P/Q$, where $\operatorname{deg} P < \operatorname{deg} Q$ by reducing it to $[x^{n/2}] F_e/V$ or $[x^{(n-1)/2}] F_o/V$, where $F_e(x^2)+xF_o(x^2) = P(x)Q(-x)$, $V(x^2) = Q(x)Q(-x)$.
 * Time: O(d \log d \log n)
 * Status: Tested https://judge.yosupo.jp/submission/251152
 */

#include "NumberTheoreticTransform.h"

template <class T>
T bostan_mori(vector<T> p, vector<T> q, ll n) {
  const int sz = bit_ceil(q.size() * 2 - 1);
  vector<T> iw(sz); iw[1] = 1, ntt(iw), reverse(1+all(iw));
  T c = 1;
  for (; n; n /= 2, c = c * c % mod * sz % mod) {
    p.resize(sz), q.resize(sz), ntt(p), ntt(q);
    rep(i, sz) p[i] = p[i] * q[i^(sz/2)] %= mod;
    rep(i, sz/2)
      p[i] = n % 2 ? (p[i] + mod - p[i+sz/2]) * iw[i] % mod
                   : p[i] + p[i+sz/2],
      q[i] = q[i] * q[i+sz/2] * 2 % mod;
    p.resize(sz/2), q.resize(sz/2), ntt(p), ntt(q);
    reverse(1+all(p)), reverse(1+all(q));
  }
  return p[0] * modpow(c, mod - 2) % mod;
}
