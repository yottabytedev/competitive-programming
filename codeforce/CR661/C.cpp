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

ll getPairsCount(vll arr, ll n, ll sum) 
{ 
    ll count = 0; // Initialize result 
  
    // // Consider all possible pairs and check their sums 
    // for (ll i=0; i<n; i++) 
    //     for (ll j=i+1; j<n; j++) 
    //         if (arr[i]+arr[j] == sum) 
    //             count++; 

	vll visited(n,0);
	for(ll i=0;i<n-1;i++){
		for(ll j=i+1;j<n;j++){
			if(arr[i]+arr[j]==sum && visited[i]==0 && visited[j]==0){
				count++;
				visited[i]=1;
				visited[j]=1;
			//cout<<arr[i]<< " "<<arr[j]<<" "<<count<<endl;

			}
		}
	}
  
    return count; 
} 

void solve(){
	cin>>n;
	vll W;
	W.resize(n);
	for(auto &w: W){
		cin>>w;
	}
	sort(W.begin(),W.end());

	ll minsum=W[0]+W[1];
	ll maxsum=W[n-1]+W[n-2];
	ll result=INT_MIN;
	for(ll i=minsum;i<=maxsum;i++){
		result=max(result,getPairsCount(W,n,i));
	}
	deb1(result);
}
 
int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}