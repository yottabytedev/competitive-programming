#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n);
        for(auto &i:a){
            cin>>i;
        }
        
        bool f = 1;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            if(find(a.begin(),a.end(),x)!=a.end()  && f){
                cout<<"YES\n1 "<<x<<endl;
                f=0;
            }
        }
        if(f)
            cout<<"NO"<<endl;
    }
    return 0;
}