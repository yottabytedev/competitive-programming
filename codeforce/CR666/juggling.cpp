#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string s;
        int C[26] = {0};
        for(int i=0;i<n;i++){
            cin>>s;
            for(char c:s){
                C[c-'a']++;
            }
        }


        bool result = true;
        for(int i = 0; i < 26; i++){
            if(C[i]%n != 0)
                result = false;
        }

        if(result)
            cout << "YES" <<endl;
        else
            cout << "NO" << endl;
    }
}