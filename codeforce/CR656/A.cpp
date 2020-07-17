#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int flag = 1;
    while(t--) {
        flag = 1;
        long long int x,y,z;
        cin>>x>>y>>z;
        long long int a,b,c,m;
        m = max(max(x,y),z);
        if (x == y && y == z && x == z) {
            a = b = c = x;
        }   else if ( x == y && x == m) {
            a = x;
            b = z;
            c = z;
        } else if ( x == z && x == m) {
            b = x;
            a = c = y;
        } else if ( y == z && y == m) {
            c = z;
            a = b = x;
        } else {
            flag = 0;
        }
        if (flag == 1) {
            cout<<"YES"<<endl;
            cout<<a<<" "<<b<<" "<<c<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}