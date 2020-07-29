class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int pB = 0, ewB = INT_MIN, ps = 0, ewS = 0;
        for(int i=0;i<n;i++){
            pB = ewB;
            ewB = max(ewB,ps-prices[i]);
            ps = ewS;
            ewS = max(ewS,pB+prices[i]);
        }
        return ewS;
    }
};