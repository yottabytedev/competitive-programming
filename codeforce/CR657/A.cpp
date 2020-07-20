#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
	cin >> t;
 
	for(int x = 0; x < t; x++) {
		int n;
		cin >> n;
 
		string s;
		cin >> s;
 
		bool done = false;
		for(int i = 0; i + 7 <= n; i++) {
			string t = s.substr(i, 7);
 
			bool ok = true;
			for(int j = 0; j < 7; j++) {
				ok = ok && (t[j] == '?' || t[j] == "abacaba"[j]);
			}
 
			if(ok) {
				string ss = s;
				for(int j = 0; j < 7; j++) {
					ss[i + j] = "abacaba"[j];
				}
				for(int j = 0; j < n; j++) {
					if(ss[j] == '?') {
						ss[j] = 'z';
					}
				}
				int cnt = 0;
				for(int k = 0; k + 7 <= n; k++) {
					string tt = ss.substr(k, 7);
					if(tt == "abacaba") {
						cnt++;
					}
				}
				if(cnt == 1) {
					cout << "Yes\n" << ss << "\n";
					done = true;
					break;
				}
			}
		}
		if(!done) {
			cout << "No\n";
		}
	}
 
	return 0;
}