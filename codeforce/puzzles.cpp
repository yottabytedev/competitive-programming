#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> F(m);
    for(int i = 0; i < m; i++){
        cin >> F[i];
    }

    sort(F.begin(), F.end());
    
    int result = INT_MAX;

    for(int i = 0; i + n - 1 < m ; i++){
        result = min( result, F[i+n-1] - F[i]);
    }

    cout << result << endl;
}