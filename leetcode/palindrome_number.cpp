#define imax INT_MAX/10
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int r = 0;
        int temp = x;
        while(x) {
            int p = x%10;
            if (r > imax || (r==imax && p>7)) return false;
            r = r*10 + p;
            x /= 10;
        }
        if ((r-temp) == 0) return true;
        else return false;
    }
};



//	Runtime: 20 ms, faster than 43.42% of C++ online submissions for Palindrome Number.
//	Memory Usage: 5.8 MB, less than 93.88% of C++ online submissions for Palindrome Number.