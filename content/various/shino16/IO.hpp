/**
 * Author: Masato Shinokawa
 * Description: IO cheat sheet
 */

void ints(auto& ...ints) { (scanf("%d ", &ints), ...); }
void lls(auto& ...lls) { (scanf("%lld ", &lls), ...); }
// skip whitespace and re-initialize s with a line (without \n)
void read_line(char *s) {scanf(" "), fgets(s, INT_MAX, stdin);}
void read_line(string &s) { cin >> ws, getline(cin, s); }
void print_vec(vector<int> v) {
  rep(i, v.size()) printf("%d%c", v[i], " \n"[i==v.size()-1]);
}
void print_arr(int *a, int n) {
  rep(i, n) printf("%d%c", a[i], " \n"[i==n-1]);
}
