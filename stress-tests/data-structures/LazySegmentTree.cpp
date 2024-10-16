#include "../utilities/template.h"

#include "../../content/data-structures/LazySegmentTree.h"
#include <climits>

static unsigned R;
int ra() {
	R *= 791231;
	R += 1231;
	return (int)(R >> 1);
}

int res;
lazy_segtree<16> tr;
int main() {
	int N = 10;
	vi v(N);
	iota(all(v), 0);
	random_shuffle(all(v), [](int x) { return ra() % x; });
	rep(i,0,N) tr.val[i+16] = v[i];
	for (int i = 16; i --> 1;) tr.val[i] = max(tr.val[i*2], tr.val[i*2+1]);
	rep(i,0,N) rep(j,0,N) if (i <= j) {
		int ma = INT_MIN;
		rep(k,i,j) ma = max(ma, v[k]);
		assert(ma == tr.prod(i,j));
	}
	rep(it,0,1000000) {
		int i = ra() % (N+1), j = ra() % (N+1);
		if (i > j) swap(i, j);
		int x = (ra() % 10) - 5;

		int r = ra() % 100;
		if (r < 30) {
			::res = tr.prod(i, j);
			int ma = INT_MIN;
			rep(k,i,j) ma = max(ma, v[k]);
			assert(ma == ::res);
		}
		else {
			tr.apply(i, j, x);
			rep(k,i,j) v[k] += x;
		}
	}
	cout<<"Tests passed!"<<endl;
}
