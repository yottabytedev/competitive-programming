#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main()
{
    lli t;
    cin>>t;
    while(t--) {
        lli n;
        cin>>n;
        vector<lli> arr;
        lli temp;
        for (lli i=0;i<n;i++) {
            cin>>temp;
            arr.push_back(temp);
        }
        lli start = n;
        lli mx = INT_MIN;

        lli i=n-1;
        while(mx<=arr[i]) {
            mx=arr[i];
            start = i;
            i--;
        }
        while(arr[i]<=mx) {
            mx=arr[i];
            start = i;
            i--;
        }
        lli zero = 0;
        start = max(start,zero);
        cout<<start<<endl;
    }
    return 0;
}