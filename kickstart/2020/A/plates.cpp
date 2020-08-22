#include <bits/stdc++.h>
using namespace std ;

int n,k,p;
int A[51][1501],S[51][1501];
int dp[51][1501];

int main() {
    int t ; cin >> t ;
    for(int cs = 1 ; cs <= t ; cs++) {
        int n, k, p; cin >> n >> k >> p;
        memset(A,0,sizeof(int)*(n+1)*(k+1));
        memset(S,0,sizeof(int)*(n+1)*(k+1));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= k; j++){
                cin >> A[i][j];
                S[i][j] = ((j>0)?S[i][j-1]:0) + A[i][j];
            }
        }

        memset(dp,0,sizeof(int)*(n+1)*(k+1));

        for(int i=1;i<=n;i++){
            for(int j=0;j<=p;j++){
                dp[i][j] = 0;
                for(int x=0;x<=min(j,k);x++){
                    dp[i][j] = max(dp[i][j],S[i][x]+dp[i-1][j-x]);
                }
            }
        }

        printf("Case #%d: %d\n", cs, dp[n][p]) ;
    }
}
