vector<vector<int>> result;
void DFS(int v,int d, vector<bool> visited,vector<vector<int>>& graph,vector<int> path){
    visited[v]=true;
    path.push_back(v);
    cout<<v<<" ";


    if (v==d){
        result.push_back(path);
    }
    else {
        for(auto i:graph[v]){
            if(!visited[i]){
                DFS(i,d,visited,graph,path);
            }
            cout<<endl;
        }
    }
}
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<int> path;
        DFS(0,n-1,visited,graph,path);
        vector<vector<int>> output = result;
        result = (vector<vector<int> >)(0);
        return output;
    }
};