#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> product = {{0,0},
                                    {0,0}};
    for (int i=0;i<2;i++)
        for (int j=0; j<2 ; j++)
            for (int k=0; k<2 ; k++)
                product[i][k] += (a[i][j] * b[j][k]) % mod;
    
    return product;
}

vector<vector<int>> expo_power(vector<vector<int>> a, int n)
{
    vector<vector<int>> res {{1,0},
                            {0,1}};
    while (n>0) {
        if (n%2 == 1) {
            res = multiply(res,a);
        }
        n /= 2;
        a = multiply(a,a);
    }
    return res;
}

int main()
{
    vector<vector<int>> a { {19,7}, 
                            {6,20} };
    int n;
    cin>>n;
    vector<vector<int>> result = expo_power(a,n);
    cout<<result[0][0];
    return 0;
}


/*
    Solution 1
    int happy = 1;
    int sad = 0;
    for (int i = 0; i < n; i++) {
        int new_happy = 19 * happy + 6 * sad;
        int new_sad = 7 * happy + 20 * sad;
        happy = new_happy;
        sad = new_sad;
    }

    Solution 2

    int dp[2] = {1,0};
    for (int i = 0; i < n; i++) {
        int new_dp[2] = {0, 0};
        new_dp[0] += dp[0] * 19;
        new_dp[1] += dp[0] * 7;
        new_dp[0] += dp[1]  * 6;
        new_dp[1] += dp[1] * 20;
        dp = new_dp;        //  new_dp[j] += dp[i] + m[i][j]
    }
*/