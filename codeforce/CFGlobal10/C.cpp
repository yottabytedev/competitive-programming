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

bool nondec(vll A){
    for(ll i=0; i<(A.size()-1); i++){
        if(A[i+1]<A[i]) return true;
        cout<<i<<" "<<endl;
    }
    return false;
}

ll minelement(vll A){
    ll output=A[0];
    for(ll i=0;i<A.size();i++){
        if(A[i]<output) output=A[i];
    }
    return output;
}

void solve(){
	cin>>n;
    vll A(n);
    for(auto &a:A){
        cin>>a;
    }
    ll result = 0;
    int s=1,e=n-1;
    ll mn = minelement(A);
    cout<<mn;
    while(nondec(A)){
        while(A[s]!=mn){
            s++;
        }
        e=s;
        while(A[s]==mn){
            e++;
        }
        for(ll i=s;i<=e;i++){
            A[i]++;
        }
        result++;
        s=0;
        mn = minelement(A);
        cout<<"Result:"<<result<<" mn:"<<mn<<endl;
    }
    deb1(result)
}
 
int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}