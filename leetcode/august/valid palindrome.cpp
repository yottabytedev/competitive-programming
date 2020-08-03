class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.length()-1;
        while(start<end){
            while(!isalnum(s[start]) && start<end) start++;
            while(!isalnum(s[end]) && start<end) end--;
            if(tolower(s[start])==tolower(s[end])){
                start++;
                end--;
            } else {
                cout<<s[start]<<" "<<s[end]<<endl;
                return false;
            }
        }
        return true;
    }
};