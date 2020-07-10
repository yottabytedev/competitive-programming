#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n,k,temp;
        cin>>n>>k;
        vector<lli> arr;
        for(lli i=0;i<n;i++) 
        {
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(),arr.end(),greater<lli>());
        
        lli x = 0, i = 0;
        while(i != n)
        {
            if (arr[i]%k == 0)
            {
                i++;
            }
            else {
                if ((arr[i] + x )%k == 0)
                {
                    arr[i] += x;
                    x++;
                    i++;
                }
                else {
                    x++;
                }
            }    
        }
        cout<<x<<endl;
    }
    return 0;
}