class Solution {
public:
    string toGoatLatin(string S) {
        int index = 1;
        map<char,int> vowel;
        vowel['a']=1; 
        vowel['e']=1;
        vowel['i']=1;
        vowel['o']=1;
        vowel['u']=1;
        vowel['A']=1;
        vowel['E']=1;
        vowel['I']=1;
        vowel['O']=1;
        vowel['U']=1;

        
        string result;
        
        bool first=true;
        string temp;
        for(char c:S){
            if(first  && vowel[c] == 1) {
                result += c;
                first = false;
            } else {
                if( first && vowel[c] != 1){
                    temp += c;
                    first = false;
                } else {
                    if(c == ' '){
                        if(temp.length()!=0) {
                            result += temp;
                        }
                        result += "ma" + string(index,'a') + " ";
                        index++;
                        first = true;
                        temp = "";
                    } else {
                        result += c;
                    }
                }
            }
        }
        
        if(temp.length()!=0) {
            result += temp;
        }
        result += "ma" + string(index,'a');
        
        return result;
    }
};