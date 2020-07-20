#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
signed main() {
	int t;
	cin >> t;
 
	for(int x = 0; x < t; x++) {
		int n, m;
		cin >> n >> m;
 
		vector< pair<int, int> > arr;
		for(int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			arr.emplace_back(a, b);
		}
		sort(arr.begin(), arr.end());
		vector<int> sufsum(m);
		sufsum[m - 1] = arr[m - 1].first;
		for(int i = m - 2; i >= 0; i--) {
			sufsum[i] = sufsum[i + 1] + arr[i].first;
		}
 
		int ans = 0;
		for(int i = 0; i < m; i++) {
			int j = lower_bound(arr.begin(), arr.end(), make_pair(arr[i].second + 1, 0LL)) - arr.begin();
 
			int cnt = m - j;
			if(cnt > n - 1) {
				cnt = n - 1;
				j = m - cnt;
			}
 
			if(cnt == n - 1 && i >= j && j >= 1 && arr[j - 1].first > arr[i].second) {
				j--;
				cnt++;
			}
 
			if(i < j) {
				cnt++;
			}
 
			assert(cnt <= n);
			int c = (j == m ? 0 : sufsum[j]) + (i < j ? arr[i].first : 0) + (n - cnt) * arr[i].second;
			ans = max(ans, c);
		}
		cout << ans << "\n";
	}
 
	return 0;
}