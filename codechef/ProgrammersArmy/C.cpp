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
 
int test = 1, n,m;
vll res;

void decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[10000]; 
  
    // counter for binary array 
    ll i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing binary array in reverse order 
    for (ll j = i - 1; j >= 0; j--) 
        cout << binaryNum[j]; 
} 

void solve(){
	cin>>n>>m;
    string chef,ada;
    vll C(n),A(m);
    For(i,n){cin>>C[i];}
    cin>>chef;
    For(i,m){cin>>A[i];}
    cin>>ada;
    ll dp[n+1][m+1] = {0};
    memset(dp,0,sizeof(dp));
    dp[0][0]=0;
    ll mx = 0;
    for(ll i=1;i<n+1;i++){
        for(ll j=1;j<m+1;j++){
            if(A[i-1]==C[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = 0;
            }
            mx = max(mx,dp[i][j]);
        }
    }
    int mxi = max(mx-1,0LL);
    int xr = chef[mxi]^ada[mxi];
    if(xr==0){
        deb1(0)
        return;
    }
    decToBinary(xr);
    memset(dp,0,sizeof(dp));
}
 
int main(){
	GODSPEED;
	cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}