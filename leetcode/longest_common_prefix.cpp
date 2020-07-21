class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();
        if (n==0) return "";
        if (n==1)   return arr[0];
        
        sort(arr.begin(),arr.end());
        int sm = arr[0].length();
        int mx = 0;
        string ref = arr[0];
        bool ok = true;
        
        for (int i=0;i<sm;i++) {
            for (int j=1;j<n;j++){
                if(ref[i]!=arr[j][i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                mx++;
            } else {
                break;
            }
        }
        return ref.substr(0,mx);
    }
};

//	class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        int n = arr.size();
        if (n==0) return "";
        if (n==1)   return arr[0];
        
        sort(arr.begin(),arr.end());
        int sm = arr[0].length();
        int mx = 0;
        string ref = arr[0];
        bool ok = true;
        
        for (int i=0;i<sm;i++) {
            for (int j=1;j<n;j++){
                if(ref[i]!=arr[j][i])
                {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                mx++;
            } else {
                break;
            }
        }
        return ref.substr(0,mx);
    }
};

//	Runtime: 8 ms, faster than 73.16% of C++ online submissions for Longest Common Prefix.
//	Memory Usage: 9.3 MB, less than 59.27% of C++ online submissions for Longest Common Prefix.