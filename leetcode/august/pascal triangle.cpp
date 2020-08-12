class Solution {
public:
    vector<int> getRow(int k) {
        vector<int> vec(k+1,1);
        for(int i=2;i<=k;i++)
            for(int j=i-1;j>0;j--)
                vec[j]+=vec[j-1];
        return vec;
    }
};