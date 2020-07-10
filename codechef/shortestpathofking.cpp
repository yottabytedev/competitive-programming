#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
 
using namespace std;
 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}
 
string ds[] = {"L", "R", "U", "D", "LU", "LD", "RU", "RD"};
int dx[] = {-1,1,0,0,-1,-1,1,1}, dy[] = {0,0,1,-1,1,-1,1,-1};
 
int dist[8][8][8][8];
 
void parse(string &s, int &x, int &y){
    x = s[0] - 'a';
    y = s[1] - '1';
}
 
int main(void){
    int i,j,k,l,i2,j2,k2,i3,j3,k3,sx,sy,gx,gy;
    string start,goal;
    
    cin >> start >> goal;
    parse(start,sx,sy); parse(goal,gx,gy);
    
    REP(i,8) REP(j,8) REP(k,8) REP(l,8){
        if(i == k && j == l) dist[i][j][k][l] = 0;
        else if(max(abs(i-k),abs(j-l)) == 1) dist[i][j][k][l] = 1;
        else dist[i][j][k][l] = (1<<29);
    }
    
    REP(k2,8) REP(k3,8) REP(i2,8) REP(i3,8) REP(j2,8) REP(j3,8) dist[i2][i3][j2][j3] = min(dist[i2][i3][j2][j3],dist[i2][i3][k2][k3]+dist[k2][k3][j2][j3]);
    
    int d = dist[sx][sy][gx][gy];
    cout << d << endl;
    while(d > 0){
        REP(i,8){
            int x = sx + dx[i], y = sy + dy[i];
            if(x >= 0 && x < 8 && y >= 0 && y < 8 && dist[x][y][gx][gy] < d){
                sx = x; sy = y; d--;
                cout << ds[i] << endl;
                break;
            }
        }
    }
    REP(k2,8){ REP(k3,8) {REP(i2,8) {REP(i3,8) {cout<<dist[k2][k3][i2][i3]<<" ";} cout<<endl;}cout<<endl;}cout<<endl;}
    
    return 0;
}