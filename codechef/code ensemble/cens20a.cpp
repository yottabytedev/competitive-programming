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
 
int test = 1, n, m;

void solve(){
	cin>>n>>m;
    int A[n][m];

    char c;
    For(i,n){
        For(j,m){
            cin>>c;
            if(c=='0') A[i][j] = 0;
            else A[i][j] = 1;
        }
    }
    
    
    bool dp[n+1][m+1]={false};
    ll Q;
    cin>>Q;
    For(q,Q){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        x1--;
        y1--;
        // for(int i=x1;i<=x2;i++){
        //     for(int j=y1;j<=y2;j++){
        //         if(A[i][j] == 1) A[i][j] = 0;
        //         else A[i][j] = 1;
        //     }
        // }
        dp[x1][y1] ^= true;
        dp[x1][y2] ^= true;
        dp[x2][y1] ^= true;
        dp[x2][y2] ^= true;
    }

    For(i,n){
        bool cur = false;
        For(j,m){
            cur ^= dp[i][j];
            dp[i+1][j] ^= dp[i][j];
            if(cur) {
                A[i][j] = 1 - A[i][j];
            }
            cout<<A[i][j];
        }
        cout<<endl;
    }
}
 
int main(){
	GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}