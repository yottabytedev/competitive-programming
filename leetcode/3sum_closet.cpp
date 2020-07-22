int val(int result,int sm, int target){
    return abs(result-target)<abs(sm-target)?result:sm;
}
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result=nums[0]+nums[1]+nums[2];
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int a = nums[i];
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int sm = a+nums[j]+nums[k];
                if(sm<target) {j++;}
                else if(sm>target) {k--;}
                    else {
                        return target;
                    }
                result=val(result,sm,target);
                while(i+1<n && nums[i+1] == nums[i]) i++;
            }
        }
        return result;
    }
};

//	Runtime: 20 ms, faster than 51.59% of C++ online submissions for 3Sum Closest.
//	Memory Usage: 9.9 MB, less than 65.99% of C++ online submissions for 3Sum Closest.