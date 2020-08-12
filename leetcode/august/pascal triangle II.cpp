int ncr(int ncr1,int n,int r){
    return (ncr1/r)*(n-r+1);
}
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0){
            vector<int> result(1,1);
            return result;
        }
        // vector<long long> fact(rowIndex+1,1);
        // for(int i=1;i<=rowIndex;i++){
        //     fact[i] = i*fact[i-1];
        // }
        vector<int> result(rowIndex+1,1);
        for(int i=1;i<=(rowIndex+1)/2;i++){
            int temp = ncr(result[i-1],rowIndex,i);
            result[i]=temp;
        }
        for(int i=((rowIndex+1)/2);i<=rowIndex;i++){
            result[i]=result[rowIndex-i];
        }
        result[rowIndex]=1;
        return result;
    }
};