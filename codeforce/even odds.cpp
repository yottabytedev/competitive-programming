#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    ll n, k;
    cin >> n >> k;
    ll o , e;
    if((n & 1) == 0){
        o = e = n/2;
    } else {
        o = (n+1)/2;
        e = n/2;
    }
    if(k>o){
        k -= o;
        cout << (2*k) << endl;
    } else {
        cout << (2*k - 1) << endl;
    }
}