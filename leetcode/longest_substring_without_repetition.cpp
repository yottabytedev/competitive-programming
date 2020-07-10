class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> visited(256,-1);
        int ls = 0;
        int i = 0;
        for (int j=0;j<n;j++)
        {
            i = max(i,visited[s[j]]+1);
            ls = max(ls,j-i+1);
            visited[s[j]]=j;
        }
        return ls;
    }
};


// Runtime 16 ms
// Memory 8.4 MB