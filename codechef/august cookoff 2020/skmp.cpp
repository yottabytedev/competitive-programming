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
 
int test = 1;

void solve(){

	string s,p;
	cin>>s>>p;

	if(s.length() == p.length()) {
		deb1(p)
		return;
	}
	
	unordered_map<char,int> sr;

	for(char i:s){
		sr[i]++;
	}
	char pcheck = p[0];
	for(char i:p){
		sr[i]--;
		if(i!=p[0] && pcheck==p[0]){
			pcheck=i;
		}
	}

	string left="",right="";
	for(auto i:sr){
		if(i.first<p[0]) left += string(i.second,i.first);
		if(i.first==p[0]) {
			if(pcheck<i.first) right+= string(i.second,i.first);
			else left+= string(i.second,i.first);
		}
		if(i.first>p[0]) right += string(i.second,i.first);
	}

	sort(left.begin(),left.end());
	sort(right.begin(),right.end());

	string result = left + p + right;
	cout<<result<<endl;
	return;
	
	
}
 
int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}