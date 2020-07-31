#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        int k=0;
        for(auto &i:arr){
            cin>>i;
        }
        for(int i=0;i<n;i++){
            if(arr[i]==1) k++;
            else break;
        }
        if(k==n) k--;
        if(k%2==0) cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
}