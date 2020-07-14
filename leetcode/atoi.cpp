class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int sign = 1;
        
        int start = 0;
        while(str[start]==' ') start++;
        
        char c;
        if (str[start] == '+') {sign = 1; start++;}
        else if (str[start] == '-') {sign = -1; start++;}
                else if (!(str[start]>47 && str[start]<58)) return (sign*res);
                    
        for (int i = start;i<str.length();i++) {
            c = str[i];
            if(c>47 && c<58){ 
                if (sign>0) {
                    if(res> INT_MAX/10 || (res == INT_MAX/10 && (c-48)>7))
                        return INT_MAX;
                } else {
                    if((-1*res)< INT_MIN/10 || (-1*res == INT_MIN/10 && (c-48)>7)) 
                        return INT_MIN;
                }
                    
                res = res*10 + c-48;
            } else return(sign*res);
        } 
        return (sign*res);
        
    }
};

//  O(len(str))
//  Runtime: 8 ms, faster than 33.44% of C++ online submissions for String to Integer (atoi).
//  Memory Usage: 6.2 MB, less than 78.86% of C++ online submissions for String to Integer (atoi).