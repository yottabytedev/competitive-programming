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
 
int test = 1, n;

ll area(ll a, ll b, ll c){
	ll p = (a+b+c)/2;
	if((p-a)<1 || (p-b)<1 || (p-c)<1 || p<1) return 0;
	return (sqrt(p*(p-a)*(p-b)*(p-c)));
}

void solve(){
	cin>>n;
	vll arr(n);
	for(auto &a:arr){
		cin>>a;
	}
	if(arr[0]+arr[1] <= arr.back())
		{deb3(1,2,n);}
	else
		deb1(-1);
}
 
int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}