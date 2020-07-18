#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
vector<set<int> > graph;
vector<set<int> > leaves;
struct cmp{
	bool operator() (int a,int b)const{
		if(leaves[a].size()==leaves[b].size()){
			return a<b;
		}
		return leaves[a].size()>leaves[b].size();
	}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		graph=leaves=vector<set<int> >(n);
		for(int i=0;i<n-1;++i){
			int u,v;
			cin>>u>>v;
			u--,v--;
			graph[u].insert(v);
			graph[v].insert(u);
		}
		for(int i=0;i<n;++i){
			if(graph[i].size()==1){
				leaves[*graph[i].begin()].insert(i);
			}
		}
		set<int,cmp> st;
		for(int i=0;i<n;++i){
			st.insert(i);
		}
		int ans=0;
		while(1){
			int u=*st.begin();
			if(int(leaves[u].size())<k){
				break;
			}
			for(int i=0;i<k;++i){
				int v=*leaves[u].begin();
				graph[v].erase(u);
				graph[u].erase(v);
				st.erase(u);
				st.erase(v);
				leaves[u].erase(v);
				if(leaves[v].count(u)){
					leaves[v].erase(u);
				}
				if(graph[u].size()==1){
					int to=*graph[u].begin();
					st.erase(to);
					leaves[to].insert(u); 
					st.insert(to);
				}
				st.insert(u);
				st.insert(v);
			}
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}