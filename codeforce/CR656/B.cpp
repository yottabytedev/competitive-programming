#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr;
        int temp;
        for (int i=0;i<2*n;i++) {
            cin>>temp;
            arr.push_back(temp);
        }
        vector<bool> visited(n+1,false);
        vector<int> original;
        for (int i=0;i<2*n;i++) {
            if (visited[arr[i]] != true) {
                original.push_back(arr[i]);
                visited[arr[i]] = true;
            }
        }
        for (int i = 0;i<n;i++) {
            cout<<original[i]<<" ";
        }
        cout<<endl;

    }
    return 0;
}