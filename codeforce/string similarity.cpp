#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string result;
        for(int i=0;i < 2*n -1; i += 2){
            result += s[i];
        }
        cout << result << endl;
    }
    
}