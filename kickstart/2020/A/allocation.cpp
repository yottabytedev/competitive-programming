#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        long long N,B;
        cin>>N>>B;
        vector<int> A(N);
        for(int &a:A){
            cin>>a;
        }
        sort(A.begin(),A.end());
        long long sum = 0;
        int index = 0;
        while(sum+A[index]<=B){
            sum+=A[index++];
        }
    
        cout<<"Case #"<<i<<" "<<index<<endl;
    }
    return 0;
}