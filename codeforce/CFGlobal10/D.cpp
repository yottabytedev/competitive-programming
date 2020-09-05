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
vll res;

void solve(){
	
	cin>>n;
    string s;
    cin >> s;

    if(count(s.begin(),s.end(),'L') == n || count(s.begin(),s.end(),'R') == n) {
        deb1((n+2)/3)
        return;
    }

    for(int i=1;i<n;i++){
        if(s[i-1]!=s[i]){
            rotate(s.begin(),s.begin()+i,s.end());
            break;
        }
    }
    
    ll omkar = 0;
    
    int count = 0;
    char previous;

    for(auto c:s){
        if(c == previous)
            count++;
        else {
            if(count>0) {
                omkar += count/3;
            }
            previous = c;
            count = 1;
        }
    }
    if(count > 0){
        omkar += count/3;
    }

    deb1(omkar)
}
 
int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}