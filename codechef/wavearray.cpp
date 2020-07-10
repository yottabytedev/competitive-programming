#include <bits/stdc++.h>
using namespace std;

vector<int> wave(vector<int> &A) {
    int n = A.size();
    sort (A.begin(),A.end());
    cout<<"hi";
    for (int i = 0; i+1 < n; i=i+2)
    {
        swap(A[i],A[i+1]);
    }
    return A;
}


int main()
{
    vector<int > output{1,2,3,4};
    cout<<"hi";
    output = wave(output);
    for(int i=0;i<output.size(); i++) {
     // for (int j=0;j<output[i].size(); j++)
        cout << output[i]<< " "; 
      //cout << endl;
   }
    return 0;
}