class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[n-1]>nums[0] || n == 1) return nums[0];
        int index = n-1;
        int mn = nums[n-1];
        while(nums[index-1]<=mn && index>1){
            mn = nums[index-1];
            index--;
        }
        return mn;
    }
};