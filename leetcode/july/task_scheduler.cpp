class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        vector<int> freq(256,0);
        int mx = 0;
        int ans = 0;
        for(int i=0;i<m;i++){
            freq[tasks[i]]++;
            if(freq[tasks[i]]>mx){
                mx = freq[tasks[i]];
            }
        }
        
        for(int i=65;i<=90;i++){
            if(freq[i]==mx) ans++;
        }
        int result = max(m,ans+(n+1)*(mx-1));
        return result;
    }
};