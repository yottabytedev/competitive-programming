class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.length();
        if (len<=numRows || numRows == 1) return s;
        string res = "";
        int l = 2*numRows - 2;
        int k=0;
        
        while (k*l<len)
        {
            res += s[k*l];
            k++;
        }
    
        if (numRows > 2)
        {
            for (int i=1;i<numRows-1;i++)
            {
                res += s[i];
                k=1;
                while (true)
                {
                    if ((k*l-i) < len) 
                        res+=s[k*l-i];
                    else 
                        break;
                    if ((k*l+i) < len)
                        res+=s[k*l+i];
                    else 
                        break;

                    k++;
                }
            }
        }
        
        k=0;
        
        while (k*l + numRows - 1 < len)
        {
            res += s[k*l + numRows - 1 ];
            k++;
        }
        
        return res;
        
    }
};


//  O( numRows * stringlen / numRows) ===> O( stringlen )
//  runtime 32ms      49.27%
//  memory  7.9MB     84.75%