class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int sz = citations.size();
        int md = (sz+1)/2;
        int mid = citations[md];
        if(mid == md) return mid;
        int index = md;
        while(mid != md && index>0){
            mid = citations[--index];
            if(mid == md) return mid;
        }
        return 0;
    }
};