class Solution {
public:
    bool detectCapitalUse(string word) {
        int wordlen = word.length();
        if(wordlen == 1) return true;
        
        string wordsubstr = word.substr(1,wordlen-1);
        
        int lr = 65, ur = 90;
        if(wordsubstr[wordlen-2]>ur) {
            lr = 97;
            ur = 122;
        }
        int index=wordlen-2;
        
        while(index>=0 && lr<=wordsubstr[index] && wordsubstr[index]<=ur){
            index--;
        }
        if(index>-1) return false;
        else if(97<=word[0] && word[0]<=122 && lr!=97) return false;
            else return true;
    }
};