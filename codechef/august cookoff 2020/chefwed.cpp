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
		int tables=1,fight=0;
		if(k>=n){
			map<int,int> A;
			
			for(auto &i: a){
				cin>>i;
				A[i]++;
				if(A[i]==2) fight+=2;
				if(A[i]>2) fight++;
			}
		} else {
			map<int,int> A;
			
			for(auto &i:a){
				cin>>i;
				{
					if(A[i]==0) A[i]=1;
					else {
						A[i]++;
						if(A[i]==2) fight+=2;
						else fight++;
					}
					
					if(A[i]>k) {
						tables++;
						fight = max(0,fight-2);
						A.clear();
						A[i]=1;
					}
				}
			}
		}
		
		cout<<(k*tables + fight)<<endl;
	}
	return 0;
}