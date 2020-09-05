#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        long long r,g,b,w;
        cin >> r >> g >> b >> w;

        int zero = 0;
        if (r == 0) zero++;
        if (g == 0) zero++;
        if (b == 0) zero++;

        int e = 0;

        if ( (r & 1)  == 0)  e++; 
        if ( (g & 1)  == 0)  e++; 
        if ( (b & 1)  == 0)  e++; 
        if ( (w & 1)  == 0)  e++; 

        // if(e==3) cout << "YES\n";
        // if(e==4) cout << "YES\n";
        // if(e==2) cout << "NO\n";
        if( e==3 || e==4 || ((e==1 || e==0) && zero == 0) ) cout << "YES\n";
        else cout << "NO\n";
    }
}