class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int,int> b;
        for (int i=0;i<nums.size();i++)
        { b.insert({nums[i],i});}
        
        for(int i=0;i<nums.size();i++)
        {
            if((b.find(target-nums[i]) != b.end()) && b[target-nums[i]] != i )
             {result.push_back(i);
             result.push_back(b[target-nums[i]]);
             break;}
        }
        return result;
    }
};