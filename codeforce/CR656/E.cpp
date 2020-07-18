#include <bits/stdc++.h>
using namespace std;

unordered_map<int,bool> seen;
unordered_map<int,vector<int> > directedGraph;
unordered_map<int,int> order;
int current = 1;
void dfs(int i) {
    seen[i] = true;
    for (int j: directedGraph[i]) {
        if (!seen[j]) dfs(j);
    }
    order[i] = current++;
}

int main()
{
    int t;
    cin>>t;

    while(t--) {
        int n,m;
        cin>>n>>m;

        int t,x,y;
        vector<pair<int,int> > Graph(m);
        for (int i=0; i<m ;i++) {
            cin>>t>>x>>y;
            if (t == 1) {
                directedGraph[x].push_back(y);
            }
            Graph[i] = {x,y};
        }
        for (int i=0; i <= n ;i++) {
            if (!seen[i]) dfs(i);
        }

        bool flag = false;
        for (int i=1; i <= n; i++) {
            for (int j: directedGraph[i]) {
                if (order[j] > order[i]) {
                    flag = true;
                    break;
                }
            }
        }

        if (flag) 
            cout<< "NO"<<endl;
        else {
            cout<<"YES"<<endl;
            for (auto v : Graph) {
                if (order[v.first] > order[v.second])
                    cout<<v.first<<" "<<v.second<<endl;
                else
                {
                        cout<<v.second<<" "<<v.first<<endl;
                }
                
            }
        }
        seen.clear();
        order.clear();
        directedGraph.clear();
        current = 1;
    }
    return 0;
}