/**
 * Author: Masato Shinokawa
 * Description: Returns shortest $c$ s.t. $a[i] = \sum_j c[j] \cdot a[i-j-1]$
 */

vi berlekamp_massey(const vi& a) {
  int i = 0;
  while (i < a.size() && !a[i]) i++;
  if (i == a.size()) return {};
  vi q, q2, p(i+1, 0);
  for (int d = a[i++], t = 1; i < a.size(); i++, t++) {
    int e = a[i];
    rep(j, p.size()) e = msub(e, mmul(p[j], a[i-j-1]));
    if (e) {
      int r = mdiv(e, d);
      bool swp = t + q.size() > p.size();
      if (swp) q2 = p;
      p.resize(max(p.size(), q.size() + t));
      p[t-1] = madd(p[t-1], r);
      rep(j, q.size()) p[t+j] = msub(p[t+j], mmul(r, q[j]));
      if (swp) swap(q2, q), d = e, t = 0;
    }
  }
  return p;
}
