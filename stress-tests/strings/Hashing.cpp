#include "../utilities/template.h"

#include "../../content/strings/Hashing.h"
#include "../../content/strings/Hashing.shino16.hpp"

#include <sys/time.h>
int main() {
	assert((H(1)*2+1-3).get() == 0);

	rep(it,0,10000) {
		int n = rand() % 10;
		int alpha = rand() % 10 + 1;
		string s;
		rep(i,0,n) s += (char)('a' + rand() % alpha);
		HashInterval hi(s);
		RollingHash hi2(s, n);
		set<string> strs;
		set<ull> hashes, hashes2;

		// HashInterval
		rep(i,0,n+1) rep(j,i,n+1) {
			string sub = s.substr(i, j - i);

			ull hash = hashString(sub).get();
			assert(hi.hashInterval(i, j).get() == hash);
			hashes.insert(hash);

			ull hash2 = 0;
			for (char c : sub) hash2 = hadd(hmul(hash2, R), c);
			assert(hi2.hash(i, j) == hash2);
			hashes2.insert(hash2);

			strs.insert(sub);
		}

		// getHashes
		rep(le,1,n+1) {
			auto ve = getHashes(s, le);
			assert(sz(ve) == n-le+1);
			rep(i,0,n-le+1) {
				assert(ve[i].get() == hi.hashInterval(i, i + le).get());
			}
		}

		// No collisions
		assert(sz(strs) == sz(hashes));
	}
	cout<<"Tests passed!"<<endl;
}
