class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x) {
            int p = x%10;
            x /=10;
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && p > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && p < -8)) return 0;
            rev = rev*10 + p;
        }
        return rev;
    }
};


// O(len(x))
// runtime 4ms	55.38%
// memory 5.9 MB	74.25%