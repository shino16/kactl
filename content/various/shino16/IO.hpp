/**
 * Author: Masato Shinokawa
 * Description: IO cheat sheet
 */

// skip whitespace and re-initialize s with a line (without \n)
void read_line(char *s) {scanf(" "), fgets(s, INT_MAX, stdin);}
void read_line(string &s) { cin >> ws, getline(cin, s); }
