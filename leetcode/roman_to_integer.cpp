class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> roman;
        roman.insert(pair<char,int>('I',1));
        roman.insert(pair<char,int>('V',5));
        roman.insert(pair<char,int>('X',10));
        roman.insert(pair<char,int>('L',50));
        roman.insert(pair<char,int>('C',100));
        roman.insert(pair<char,int>('D',500));
        roman.insert(pair<char,int>('M',1000));
        
        stack<char> st;
        for(int i=0;i<s.length();i++)
            st.push(s[i]);
        
        int result = 0;
        char prev = st.top();
        while(!st.empty()){
            char symbol = st.top();
            if (roman[symbol]<roman[prev]) {
                result -= roman[symbol];
            } else {
                result += roman[symbol];
            } 
            prev = symbol;
            st.pop();
        }
        return result;
    }
};

//	Runtime: 44 ms, faster than 14.22% of C++ online submissions for Roman to Integer.
//	Memory Usage: 11.7 MB, less than 5.04% of C++ online submissions for Roman to Integer.