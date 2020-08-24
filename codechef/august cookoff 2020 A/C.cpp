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
 
int test = 1, n,k, a[N], b[N], ct[N], c1[N], c2[N], vis[N];
char c;
vll res;

void solve(){
	cin>>n>>k;
	int zero=0,one=0;
	string s,sr;
	For(i,n){
		cin>>c;
		if((c-'0') == 0) zero++;
		else one++;
	}
	if(one==0 || zero==0){
		s = string(zero,'0')+string(one,'1');
		deb1(s);
		return;
	}
	int groups = n/k;
	int cone = one/groups;
	int czero = zero/groups;

	if(one%groups!=0 || zero%groups!=0){
		deb1("IMPOSSIBLE")
		return;
	} else {
		
		s = string(czero,'0') + string(cone,'1');
		sr = string(cone,'1') + string(czero,'0');
	}
	int l = n/k;
	For(i,l){
		if(i%2==0)
			cout<<s;
		else 
			cout<<sr;
	}
	cout<<endl;
	
}
 
int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}