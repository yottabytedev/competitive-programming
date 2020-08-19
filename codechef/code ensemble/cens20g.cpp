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
 
int test = 1, n, a[N], b[N], ct[N], c1[N], c2[N], vis[N];

void solve(){
    string s;
    cin>>s;
    ll U=0,D=0,R=0,L=0;
    for(char c:s){
        if(c == 'U') U++;
        if(c == 'D') D++;
        if(c == 'R') R++;
        if(c == 'L') L++;
    }
    ll x1,y1,x2,y2,q;
    cin>>x1>>y1;
    cin>>q;
    For(i,q){
        cin>>x2>>y2;
        ll x = x2 - x1;
        ll y = y2 - y1;
        ll u=0,d=0,l=0,r=0;
        if(x > 0) r = x;
        if(x < 0) l = -x;
        if(y > 0) u = y;
        if(y < 0) d = -y;
        
        ll minsteps = u + d + l + r;
        
        if(u <= U && d <= D && l <= L && r <= R) {
            deb2("YES",minsteps)
        } else {
            deb1("NO")
        }
    }    
}
 
int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}