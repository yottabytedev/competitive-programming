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
		for(int &i:a){
			cin>>i;
		}
		int dp[n+1]={0};
	    for(int i=0;i<n;i++)
	    {
	        int fre[101];
	        memset(fre,0,sizeof(fre));
	        int arg=0;
	        int cur=INT_MAX;
	        for(int j=i;j>=0;j--)
	        {
	            fre[a[j]]++;
	            if(fre[a[j]]==2)
	            arg+=2;
	            else if(fre[a[j]]>2)
	            arg++;
	            
	            int val=k+arg;
	            if(j-1>=0)
	            cur=min(cur,val+dp[j-1]);
	            else
	            cur=min(cur,val);
	        }
	        dp[i]=cur;
	    }
	    cout<<dp[n-1]<<endl;
	}
	return 0;
}