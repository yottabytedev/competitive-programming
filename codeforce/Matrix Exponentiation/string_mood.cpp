#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> product = {{0,0},
                                    {0,0}};
    for (int i=0;i<2;i++)
        for (int j=0; j<2 ; j++)
            for (int k=0; k<2 ; k++)
                product[i][k] += a[i][j] * b[j][k];
    
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