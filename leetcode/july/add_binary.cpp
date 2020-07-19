class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.length(), nb = b.length();
        if (na != nb) {
            if (na < nb) {
                int n = nb - na;
                string zeros(n,'0');
                a = zeros + a;
            } else {
                int n = na - nb;
                string zeros(n,'0');
                b = zeros + b;
            }
        }
        
        string result;
        char carry='0';
        
        for (int i= a.length()-1; i>=0 ; i--) {
            int d = (int)(a[i] + b[i] + carry);
            d -= 144;
            switch(d) {
                case 0 : result += '0';
                        carry = '0';
                    break;
                case 1 : result += '1';
                    carry = '0';
                    break;
                case 2 : result += '0';
                    carry = '1';
                    break;
                default: result += '1';
                    carry = '1';
            }
        }
        if (carry == '1') {
            result += '1';
        }
        reverse(result.begin(),result.end());
        return result;
    }
};