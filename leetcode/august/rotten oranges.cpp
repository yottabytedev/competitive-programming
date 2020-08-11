class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int min=0;
        int rotten=0,fresh=0;
        for(auto row:grid){
            for(auto cell:row){
                if(cell==2) rotten++;
                if(cell==1) fresh++;
            }
        }
        if(rotten==0 && fresh!=0) return -1;
        int flag=1;
        while(flag){
            int prevrotten=rotten;
            vector<vector<int>> temp=grid;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(grid[i][j]==2) {
                        if(i-1>=0 && grid[i-1][j]==1) {temp[i-1][j]=2;rotten++;}
                        if(i+1<n && grid[i+1][j]==1) {temp[i+1][j]=2;rotten++;}
                        if(j-1>=0 && grid[i][j-1]==1) {temp[i][j-1]=2;rotten++;}
                        if(j+1<m && grid[i][j+1]==1) {temp[i][j+1]=2;rotten++;}
                    };
                }
            }
            grid = temp;
            // for(auto row:grid){
            //     for(auto cell:row){
            //         cout<<cell<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            min++;
            if(rotten==prevrotten) {
                flag=0;
            }
        }
        for(auto row:grid){
            for(auto cell:row){
                if(cell==1) return -1;
            }
        }
        return min-1;
    }
};