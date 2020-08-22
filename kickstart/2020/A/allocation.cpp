#include <bits/stdc++.h>

using namespace std ;
int main() {
    int t ; cin >> t ;
    for(int cs = 1 ; cs <= t ; cs ++) {
        int n , b , cnt = 0 ; cin >> n >> b ;
        vector<int> a(n) ; for(int i = 0 ; i < n ; i ++) cin >> a[i] ;
        sort(a.begin(), a.end()) ;
        for(int i = 0 ; i < n ; i ++) {
            if(a[i] > b) break ;
            else {
                b -= a[i] ;
                cnt ++ ;
            }
        }
        printf("Case #%d: %d\n", cs, cnt) ;
    }
}
