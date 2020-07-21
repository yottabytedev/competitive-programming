class Solution {
public: 
	vector<vector<int> > threeSum(vector<int>& nums) {
	vector<vector<int> > result;
	int n = nums.size();
	sort(nums.begin(),nums.end());
	for(int i=0;i<n;i++){
		int a = nums[i];
		int j = i+1;
		int k = n-1;
		while(j<k) {
			int sm = nums[j]+nums[k];
			if(sm<-a) j++;
			else if(sm>-a) k--;
				else {
					result.push_back({a,nums[j],nums[k]});
					int oldj = j;
					int oldk = k;
					while(j<k && nums[j] == nums[oldj]) j++;
					while(k>j && nums[k] == nums[oldk]) k--;
				}
			while(i+1<n && nums[i+1] == nums[i]) i++;
		}
		
	}
	return result;
	}
};

//	Runtime: 92 ms, faster than 81.60% of C++ online submissions for 3Sum.
//	Memory Usage: 19.8 MB, less than 63.80% of C++ online submissions for 3Sum.