class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int h=0,index=citations.size()-1;
        while(index>-1){
            if(citations[index]>h) {
                h++;
                index--;
            } else {
                return h;
            }
        }
        return h;
    }
};