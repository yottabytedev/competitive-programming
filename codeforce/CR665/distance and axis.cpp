#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin >> n >> k;
        if( k > n)
            cout << (k-n) <<endl;
        else 
            cout << ((n-k)%2) <<endl;
    }
}