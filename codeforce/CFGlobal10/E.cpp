#include<bits/stdc++.h>
 
using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
#define  For(i,n)       for(int i=0;i<n;i++)
#define  Fori(i,n)      for(int i=n;i>=0;i--)

 
typedef  long long             ll;
typedef  long double           ld;
typedef  pair<ll,ll>           pll;
typedef  vector<ll>            vll;
typedef  unordered_map<ll,ll>  um;
typedef  vector<pll>           vpll;
 
const ll   N     =  1e6+5;
const ll   mod   =  998244353;
const ll   INF   =  0x7f7f7f7f7f7f7f7f;
const int  INFi  =  0x7f7f7f7f;
 
 
int main(){
	GODSPEED;
	
    int n;
    cin >> n;
    vector<vector<int64_t>> A(n, vector<int64_t>(n));
 
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            A[r][c] = (r & 1LL) << (r + c);
 
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            cout << A[r][c] << (c < n - 1 ? ' ' : '\n');
 
    cout << flush;
    int Q;
    cin >> Q;
 
    for (int q = 0; q < Q; q++) {
        int64_t k;
        cin >> k;
        int row = n - 1, col = n - 1;
        vector<array<int, 2>> path = {{row, col}};
 
        while (row > 0 || col > 0) {
            if (row > 0 && (k >> (row - 1 + col) & 1) == ((row - 1) & 1))
                row--;
            else
                col--;
 
            path.push_back({row, col});
        }
 
        reverse(path.begin(), path.end());
 
        for (auto &xy : path)
            cout << xy[0] + 1 << ' ' << xy[1] + 1 << '\n';
 
        cout << flush;
    }
}