#include<bits/stdc++.h>
 
using namespace std;
 
#define  GODSPEED       ios:: sync_with_stdio(0);cin.tie(0);cout.tie(0);cout<<fixed;cout<<setprecision(15);
#define  f              first                 
#define  s              second
#define  endl           "\n"
#define  pb             push_back  
#define  mp             make_pair
#define  mset(a,x)      memset(a,x,sizeof(a))
#define  debv(a)        for(auto it: a)cout<<it<<" ";cout<<endl;
#define  deb1(a)        cout<<a<<endl;
#define  deb2(a,b)      cout<<a<<" "<<b<<endl;
#define  deb3(a,b,c)    cout<<a<<" "<<b<<" "<<c<<endl;
#define  deb4(a,b,c,d)  cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;            
#define  rep(i,a,n)     for(int i=a;i<n;i++)
#define  per(i,a,n)     for(int i=n-1;i>=a;i--)

 
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

//const int N=101000;

int pb[N],pr[N],n,m,q,dp[N][2];
char L[N],R[N],U[N],D[N];
int solve(char *L,char *R,char *U,char *D,int n,int m,char r,char b) {
	dp[0][0]=dp[0][1]=0;
	rep(i,0,n) {
		dp[0][0]+=(L[i]==b);
		dp[0][1]+=(L[i]==r);
	}
	dp[0][0]+=(U[0]==b)+(D[0]==b);
	dp[0][1]+=(U[0]==r)+(D[0]==r);
	rep(i,1,m) {
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]+n)+(U[i]==b)+(D[i]==b);
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+n)+(U[i]==r)+(D[i]==r);
	}
	rep(i,0,n) {
		dp[m-1][0]+=(R[i]==b);
		dp[m-1][1]+=(R[i]==r);
	}
	return min(dp[m-1][0],dp[m-1][1]);
}
 
int main(){
	GODSPEED;
	cin>>n>>m>>q;
	cin>>L>>R>>U>>D;
	// scanf("%s%s%s%s",L,R,U,D);
	int pR=0;
	rep(i,0,n) pR+=(L[i]=='R')+(R[i]=='R');
	rep(i,0,m) pR+=(U[i]=='R')+(D[i]=='R');
	int ans = min(pR,2*(n+m)-pR);
	ans = min(ans, solve(L,R,U,D,n,m,'R','B'));
	ans = min(ans, solve(U,D,L,R,m,n,'R','B'));
	cout<<ans<<endl;
}