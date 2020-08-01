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
const int64_t INF64 = int64_t(2e18) + 5;

// Note: if there is a cycle, the size of the return will be less than n.
vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = int(adj.size());
    vector<int> in_degree(n, 0);
    vector<int> order_output;
 
    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;
 
    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            order_output.push_back(i);
 
    int current = 0;
 
    while (current < int(order_output.size())) {
        int node = order_output[current++];
 
        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order_output.push_back(neighbor);
    }
 
    return order_output;
}

int test = 1, n;
vll A,B;
vector<int64_t> dp;
vector<vector<int>> children,order;
 

void dfs(int node){
	dp[node]=A[node];

	for(auto child: children[node]){
		dfs(child);

		if(dp[child]>0){
			dp[node] += dp[child];
			order[child].push_back(node);
		} else {
			order[node].push_back(child);
		}
	}
}

void solve(){
	cin>>n;
	A.resize(n);
	B.resize(n);
	for(auto &a: A){
		cin>>a;
	}
	for(auto &b: B){
		cin>>b;
		if(b>=0) b--;
	}
	children.assign(n,{});

	For(i,n){
		if(B[i]>=0) 
			children[B[i]].push_back(i);
	}

	order.assign(n,{});
	dp.assign(n,-INF64);
	For(i,n){
		if(B[i]<0)
			dfs(i);
	}

	vector<int> result = topological_sort(order);
	assert(int(result.size())==n);
	cout<<accumulate(dp.begin(),dp.end(),0LL)<<endl;
	for(auto &r: result) r++;
	debv(result);
}
 
int main(){
	GODSPEED;
	// cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}