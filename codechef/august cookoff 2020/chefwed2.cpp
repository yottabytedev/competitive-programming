#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n);
        vector<vector<int>> dp(1001,vector<int> (101,0));
        int table=1;
        int fight=0;
		for(int &i:a){
            cin>>i;
            if(dp[table][i]==1) fight+=2;
            if(dp[table][i]>2) fight++;
            if(fight>=k){
                table++;
                fight=0;
            }
            dp[table][i]++;
        }
        int tfight = 0;
        for(int i=1;i<=table;i++){
            for(int j=0;j<=100;j++){
                if(dp[i][j]>1) 
                    tfight += dp[i][j];
            }
        }

        int result = k * table + tfight;
        cout<<result<<endl;

	}
	return 0;
}