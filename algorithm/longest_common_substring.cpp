class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
    int n = arr.size(); 
    if (n==0) {
        return "";
    }
        if (n==1) {
            return arr[0];
        }
    sort(arr.begin(),arr.end());
  
    // Take first word from array as reference 
    string s = arr[0]; 
    int len = s.length(); 
  
    string res = ""; 
  
    for (int i = 0; i < len; i++) 
    { 
        for (int j = i + 1; j <= len; j++) 
        { 
            // generating all possible substrings 
            // of our reference string arr[0] i.e s 
            string stem = s.substr(i, j); 
            int k = 1; 
            for (k = 1; k < n; k++) 
            { 
                // Check if the generated stem is 
                // common to all words
                if (arr[k].find(stem)==string::npos) 
                    break;
                
            } 
  
            // If current substring is present in 
            // all strings and its length is greater 
            // than current result 
            if (k == n && res.length() < stem.length()) 
                res = stem; 
        } 
    } 
  
    return res;
    }
};