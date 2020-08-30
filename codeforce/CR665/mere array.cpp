#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int A[n],B[n],mn = INT_MAX;
        for(int i = 0; i < n; i++){
            cin >> A[i];
            B[i] = A[i];
            mn = min(mn, A[i]);
        }

        sort(B,B+n);

        bool result = true;
        for(int i = 0; i < n; i++){
            if(A[i]%mn != 0 && A[i] != B[i])
                result = false;
        }

        if(result)
            cout << "YES" <<endl;
        else
            cout << "NO" << endl;
    }
}