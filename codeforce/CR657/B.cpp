#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        ll l,r,m,a,b,c,n;
        cin>>l>>r>>m;
        bool found = false;
        for(a=l;a<=r;a++){
            for(n=max(1LL,(m+l-r)/a);n*a+l-r<=m;n++){
                ll diff = m-n*a;
                c=r;
                b=diff+c;
                if(l<=b && b<=r && l<=c && c<=r){
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    found=true;
                    break;
                }
                b=r;
                c=b-diff;
                if(l<=b && b<=r && l<=c && c<=r){
                    cout<<a<<" "<<b<<" "<<c<<endl;
                    found=true;
                    break;
                }
            }
            if (found) 
                break;
        }
    }
    return 0;
}