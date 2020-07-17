#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int,int> &a, const pair<int,int> &b)
{
    return ( a.second > b.second );
}

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(auto i:nums) {
            freq[i]++;
        }
        vector<pair<int,int> > freq_count;
        for (auto i:freq) {
            freq_count.push_back(make_pair(i.first,i.second));
        }

        sort(freq_count.begin(),freq_count.end(),compare);

        vector<int> result;
        for (int j=0;j<k;j++){
            result.push_back(freq_count[j].first);
        }
        return result;
    }
};



int main()
{
    vector<int> nums{1};
    int k;
    cin>>k;
    Solution a;
    vector<int> result = a.topKFrequent(nums,k);
    for(auto i:result)
        cout<<i<<" ";
    return 0;
}