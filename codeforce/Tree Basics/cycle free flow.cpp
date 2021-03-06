#include <bits/stdc++.h>
 
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


template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;
 
    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }
 
    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }
 
    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }
 
    void build(const vector<T> &_values) {
        values = _values;
        n = int(values.size());
        int levels = largest_bit(n) + 1;
        range_low.resize(levels);
 
        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);
 
        for (int i = 0; i < n; i++)
            range_low[0][i] = i;
 
        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }
 
    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }
 
    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};

struct LCA {
    int n = 0;
    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;
    vector<int> euler, first_occurrence;
    vector<int> tour_start, tour_end, postorder;
    vector<int> tour_list, rev_tour_list;
    vector<int> heavy_root;
    RMQ<int> rmq;
    bool built;
 
    LCA(int _n = 0) {
        init(_n);
    }
 
    // Warning: this does not call build().
    LCA(const vector<vector<int>> &_adj) {
        init(_adj);
    }
 
    void init(int _n) {
        n = _n;
        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);
        first_occurrence.resize(n);
        tour_start.resize(n);
        tour_end.resize(n);
        postorder.resize(n);
        tour_list.resize(n);
        heavy_root.resize(n);
        built = false;
    }
 
    // Warning: this does not call build().
    void init(const vector<vector<int>> &_adj) {
        init(int(_adj.size()));
        adj = _adj;
    }
 
    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
 
    int degree(int v) const {
        return int(adj[v].size()) + (built && parent[v] >= 0);
    }
 
    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;
 
        // Erase the edge to parent.
        adj[node].erase(remove(adj[node].begin(), adj[node].end(), par), adj[node].end());
 
        for (int child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
 
        // Heavy-light subtree reordering.
        sort(adj[node].begin(), adj[node].end(), [&](int a, int b) {
            return subtree_size[a] > subtree_size[b];
        });
    }
 
    int tour, post_tour;
 
    void tour_dfs(int node, bool heavy) {
        heavy_root[node] = heavy ? heavy_root[parent[node]] : node;
        first_occurrence[node] = int(euler.size());
        euler.push_back(node);
        tour_list[tour] = node;
        tour_start[node] = tour++;
        bool heavy_child = true;
 
        for (int child : adj[node]) {
            tour_dfs(child, heavy_child);
            euler.push_back(node);
            heavy_child = false;
        }
 
        tour_end[node] = tour;
        postorder[node] = post_tour++;
    }
 
    void build(int root = -1) {
        parent.assign(n, -1);
 
        if (0 <= root && root < n)
            dfs(root, -1);
 
        for (int i = 0; i < n; i++)
            if (i != root && parent[i] < 0)
                dfs(i, -1);
 
        tour = post_tour = 0;
        euler.clear();
        euler.reserve(2 * n);
 
        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                tour_dfs(i, false);
                // Add a -1 in between connected components to help us detect when nodes aren't connected.
                euler.push_back(-1);
            }
 
        rev_tour_list = tour_list;
        reverse(rev_tour_list.begin(), rev_tour_list.end());
        assert(int(euler.size()) == 2 * n);
        vector<int> euler_depths;
        euler_depths.reserve(euler.size());
 
        for (int node : euler)
            euler_depths.push_back(node < 0 ? node : depth[node]);
 
        rmq.build(euler_depths);
        built = true;
    }
 
    pair<int, int> find_farthest(int node, int par, int path) const {
        pair<int, int> current = {path, node};
 
        for (int neighbor : adj[node])
            if (neighbor != par)
                current = max(current, find_farthest(neighbor, node, path + 1));
 
        return current;
    }
 
    // Warning: this must be called before build(), since build() erases half of the edges.
    pair<int, pair<int, int>> get_diameter() const {
        int u = find_farthest(0, -1, 0).second;
        pair<int, int> farthest = find_farthest(u, -1, 0);
        int v = farthest.second;
        return {farthest.first, {u, v}};
    }
 
    // Note: returns -1 if `a` and `b` aren't connected.
    int get_lca(int a, int b) const {
        a = first_occurrence[a];
        b = first_occurrence[b];
 
        if (a > b)
            swap(a, b);
 
        return euler[rmq.query_index(a, b + 1)];
    }
 
    bool is_ancestor(int a, int b) const {
        return tour_start[a] <= tour_start[b] && tour_start[b] < tour_end[a];
    }
 
    bool on_path(int x, int a, int b) const {
        return (is_ancestor(x, a) || is_ancestor(x, b)) && is_ancestor(get_lca(a, b), x);
    }
 
    int get_dist(int a, int b) const {
        return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
    }
 
    // Returns the child of `a` that is an ancestor of `b`. Assumes `a` is a strict ancestor of `b`.
    int child_ancestor(int a, int b) const {
        assert(a != b);
        assert(is_ancestor(a, b));
 
        // Note: this depends on RMQ breaking ties by latest index.
        int child = euler[rmq.query_index(first_occurrence[a], first_occurrence[b] + 1) + 1];
        assert(parent[child] == a);
        assert(is_ancestor(child, b));
        return child;
    }
 
    int get_kth_ancestor(int a, int k) const {
        while (a >= 0) {
            int root = heavy_root[a];
 
            if (depth[root] <= depth[a] - k)
                return tour_list[tour_start[a] - k];
 
            k -= depth[a] - depth[root] + 1;
            a = parent[root];
        }
 
        return a;
    }
 
    int get_kth_node_on_path(int a, int b, int k) const {
        int anc = get_lca(a, b);
        int first_half = depth[a] - depth[anc];
        int second_half = depth[b] - depth[anc];
        assert(0 <= k && k <= first_half + second_half);
 
        if (k < first_half)
            return get_kth_ancestor(a, k);
        else
            return get_kth_ancestor(b, first_half + second_half - k);
    }
 
    // Note: this is the LCA of any two nodes out of three when the third node is the root.
    // It is also the node with the minimum sum of distances to all three nodes.
    int get_common_node(int a, int b, int c) const {
        // Return the deepest node among lca(a, b), lca(b, c), and lca(c, a).
        int x = get_lca(a, b);
        int y = get_lca(b, c);
        int z = get_lca(c, a);
 
        if (depth[y] > depth[x])
            x = y;
 
        if (depth[z] > depth[x])
            x = z;
 
        return x;
    }
 
    // Given a subset of k tree nodes, computes the minimal subtree that contains all the nodes (at most 2k - 1 nodes).
    // Returns a list of {node, parent} for every node in the subtree. Runs in O(k log k).
    vector<pair<int, int>> compress_tree(vector<int> nodes) const {
        if (nodes.empty())
            return {};
 
        auto &&compare_tour = [&](int a, int b) { return tour_start[a] < tour_start[b]; };
        sort(nodes.begin(), nodes.end(), compare_tour);
        int k = int(nodes.size());
 
        for (int i = 0; i < k - 1; i++)
            nodes.push_back(get_lca(nodes[i], nodes[i + 1]));
 
        sort(nodes.begin() + k, nodes.end(), compare_tour);
        inplace_merge(nodes.begin(), nodes.begin() + k, nodes.end(), compare_tour);
        nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
        vector<pair<int, int>> result = {{nodes[0], -1}};
 
        for (int i = 1; i < int(nodes.size()); i++)
            result.emplace_back(nodes[i], get_lca(nodes[i], nodes[i - 1]));
 
        return result;
    }
};
 
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

// vector<long long> path;

void solve(){
	int n, m, u, v, q, a, b, fa, fb, j;
	ll w, mn;
	cin >> n >> m;

	LCA lca(n);

    vector<vector<pair<int,ll>>> W(n);
    // map<pair<int,int>,long long> W;
    // ll W[m][3] = {0};
	// ll W[n][n] = {0};
    // memset(W,0,sizeof(W[0][0])*n*n);
    // long long W[n][n] = {0};

	For(i,m){
		scanf("%d %d %lld",&u,&v,&w);
		u--; v--;
		lca.add_edge(u,v);
        W.at(u).push_back(make_pair(v,w));
        W.at(v).push_back(make_pair(u,w));
        // W.insert({{u,v},w});
        // W.insert({{v,u},w});
        // W[i][0] = u;
        // W[i][1] = v;
        // W[i][2] = w;

		// W[u][v] = w;
		// W[v][u] = w;
	}

	lca.build();

	cin>>q;

    ll answers[q][3];
    bool flag = false;

	For(i,q){
		cin >> a >> b;
		a--; b--;

        For(ans,i){
            if((answers[ans][0] == a && answers[ans][1] == b) || (answers[ans][1] == a && answers[ans][0] == b)){
                cout<<answers[ans][2]<<endl;
                flag = true;
                break;
            }
        }
		// 1st solution
		// vll result;
		// map<pair<int,int>,bool> v = visited;

		// int path = 0;
		// while(lca.euler[path]!=a || lca.euler[path]!=b){
		// 		path++;
		// 	}
		// path++;
		// for(; a!=lca.euler[path] || b!=lca.euler[path]; path++){
		// 	pair<int,int> temp1 = make_pair(lca.euler[path-1],lca.euler[path]);
		// 	pair<int,int> temp2 = make_pair(lca.euler[path],lca.euler[path-1]);

		// 	if(!v[temp2]) {
		// 		v[temp2] = true;
		// 		result.push_back(weight.weight_value(lca.euler[path],lca.euler[path-1]));
		// 	} else {
		// 		for(auto it = result.begin(); it != result.end(); it++){
		// 			if(*it == (weight.weight_value(lca.euler[path],lca.euler[path-1]))){
		// 				result.erase(it);
		// 				break;
		// 			}
		// 		}
		// 	}
		// }

		// 2nd solution
		// ll mn = INT_MAX;

		// int previous = a, next = a;
		// while(next!=b){
		// 	if(lca.get_dist(next,b)>1){
		// 		int next = lca.get_kth_node_on_path(next,b,1);
		// 		if(next>(n-1)) next = b;
		// 		else {
		// 			if(next<0) next = b;
		// 		}
		// 		mn = min(weight.weight_value(previous,next),mn);
		// 	} else {
		// 		mn = min(mn, weight.weight_value(next,b));
		// 		next = b;
		// 	}
		// }

        if(!flag){
            fa = lca.first_occurrence[a];
            fb = lca.first_occurrence[b];
            if(fa>fb) {swap(fa,fb);}

            vector<int> path;

            for(j=fa;j<=fb;j++){
                if(find(path.begin(),path.end(),lca.euler[j]) != path.end()){
                    path.pop_back();
                } else {
                    path.push_back(lca.euler[j]);
                }
            }
            
            mn = INF;
            for(j=1;j<path.size();j++){
                ll temp;
                for(auto k:W[path[j-1]]){
                    if(k.first == path[j])
                        {
                            temp = k.second;
                            break;
                        }
                }
                // ll temp = W[{path[j-1],path[j]}];
                // For(k,m){
                //     if((W[k][0] == path[j-1] && W[k][1] == path[j]) || (W[k][0] == path[j] && W[k][1] == path[j-1])){
                //         temp = W[k][2];
                //         break;
                //     }
                // }
                if(temp  < mn){
                    mn = temp;
                }
            }
            
            cout<<mn<<endl;
            answers[i][0] = a;
            answers[i][1] = b;
            answers[i][2] = mn;
        }
        flag = false;
		
	}
}
 
int main(){
	// GODSPEED;
	//cin>>test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}