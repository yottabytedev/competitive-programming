#include <bits/stdc++.h>
using namespace std;

const long long int INF = (long long)1e15;

int N;
int arr[101010];

__int128 abds(__int128 x)
{
    if(x>0) return x;
    return -x;
}

int main()
{
    cin >> N;
    for(int i=0; i<N; ++i)
        cin >> arr[i];
    sort(arr, arr+N);
    __int128 ans = INF;
    int cmax;
    if(N == 3) cmax = (int)1e7;
    else cmax = (int)1e7/N;
    for(int c=1; c<=cmax; ++c)
    {
        __int128 loc = 0;
        __int128 v = 1;
        for(int i=0; i<N; ++i)
        {
            loc += abds(arr[i]-v);
            if(loc > ans) break;
            v *= c;
        }
        if(ans>loc) ans = loc;
    }
    cout << (long long)ans << endl;
}