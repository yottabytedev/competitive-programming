bool match(vector<vector<char>>& board, int i, int j,int n, int m, string word,int index){
    if (i<0 || j<0 || i>=n || j>=m)
        return false;
    if(board[i][j]==word[index]){
        char temp = board[i][j];
        board[i][j] = '*';
        if (index == word.length()-1) return true;
        if (match(board,i,j-1,n,m,word,index+1) 
        || match(board,i,j+1,n,m,word,index+1) 
        || match(board,i-1,j,n,m,word,index+1)
        || match(board,i+1,j,n,m,word,index+1)) return true;
        board[i][j]=temp;
    }
    return false;
}
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        int i,j;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(board[i][j] == word[0]){
                    bool ans = match(board,i,j,n,m,word,0);
                    if(ans) return true;
                }
            }
        } 
        return false;
    }
};