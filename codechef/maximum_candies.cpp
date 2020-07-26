#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
		ll n,m,x,y;
		cin>>n>>m>>x>>y;
		
		if(n*m>1)
			x = min(x,y);
		y = min(2*x,y);
		cout<<((n*m+1)/2*x + n*m/2*(y-x))<<endl;
		
	}
	return 0;
}