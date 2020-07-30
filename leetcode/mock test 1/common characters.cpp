class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> result(A[0].size());
        for(int i=0;i<A[0].size();i++){
            result[i]=A[0][i];
        }
        int n = A.size();
        for(int i=1;i<n;i++){
            vector<string> temp;
            for(int j=0;j<result.size();j++){
                size_t found = A[i].find(result[j]); 
                if (found != string::npos) {A[i][found]='#'; temp.push_back(string(result[j]));}
            }
            result = temp;
        }
        return result;
    }
};