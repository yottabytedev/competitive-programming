#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long x1,y1,z1,x2,y2,z2,result=0;
        cin >> x1 >> y1 >> z1;
        cin >> x2 >> y2 >> z2;
        
        long long tmp = min(z1,y2);
        result = tmp * 2;
        z1 -= tmp;
        y2 -= tmp;
        tmp = min(y1,x2+y2);
        y1 -= tmp;
        if(y1){
            result -= y1 * 2;
        }
        cout << result << endl;
    }
}