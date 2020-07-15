class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length()+2, vector<bool> (p.length()+2, false));

        dp[s.length()][p.length()] = true;
        
        for (int i=s.length(); i>=0; i--){
            for (int j=p.length()-1; j>=0; j--) {
                bool match = ((s[i] == p[j]) || (p[j] == '.')) ;
                if (j+1 < p.length() && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || match && dp[i+1][j];
                } else {
                    dp[i][j] = match && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};


//	O(len(s)*len(p))
//	Runtime: 24 ms, faster than 35.62% of C++ online submissions for Regular Expression Matching.
//	Memory Usage: 6.7 MB, less than 57.84% of C++ online submissions for Regular Expression Matching.