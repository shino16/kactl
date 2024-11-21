/**
 * Author: Masato Shinokawa
 * Description: Finds row minima of $A$, a strict lower-triangular Monge matrix. This can compute $dp[i] = \min dp[j]+f(j, i)$ by setting $A[i,j] = dp[j]+f(j,i)$.
 * Status: tested https://codeforces.com/contest/319/submission/290622765
 */

template <class F>
void simplified_larsch(int n, F A) {
  // pre: A[:l], A[r][:l], post: A[:r+1]
  auto rec = [&](auto&& f, int l, int r) -> void {
    if (l == r) return;
    int m = (l+r) / 2;
    rep2(k, opt[l-1], opt[r]+1)
      if (chmin(mini[m], A(m, k))) opt[m] = k;
    f(f, l, m);
    rep2(k, l, m+1) if (chmin(mini[r], A(r, k))) opt[r] = k;
    f(f, m+1, r);
  };
  mini[0] = 0, opt[0] = 0, mini[n] = A(n, 0), opt[n] = 0;
  rec(rec, 1, n);
}
