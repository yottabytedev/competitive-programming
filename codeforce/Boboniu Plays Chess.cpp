#include <bits/stdc++.h>
#define p(a,b) cout<<a<<" "<<b<<endl;
using namespace std;

int Sx, Sy, n, m;

int main(){
    cin >> n >> m >> Sx >> Sy;
    int count = 0;

    for(int j = Sy; j >= 1; j--){
        count++;
        p(Sx,j);
    }

    for(int j = Sy + 1; j <= m; j++){
        count++;
        p(Sx,j);
    }

    int x = Sx-1, y = m;

    while(count < (n*m)){
        if(x < 1) {x = Sx + 1;}
        if(x < Sx && x >= 1){
            if(y == m){
                for(int j = y; j >= 1; j--){
                    count++;
                    p(x,j);
                }
                y = 1;
            } else {
                for (int j = y; j <= m; j++){
                    count++;
                    p(x,j);
                }
                y = m;
            }
            x--;
            continue;
        } else {
            if(y == m){
                for(int j = y; j >= 1; j--){
                    count++;
                    p(x,j);
                }
                y = 1;
            } else {
                for (int j = y; j <= m; j++){
                    count++;
                    p(x,j);
                }
                y = m;
            }
            x++;
            continue;
        }
    }

}