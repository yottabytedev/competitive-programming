#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    float p;
    cin>>n>>p;

    float prob_happy = 1.0;
    while(n>0) {
        if (n%2 == 1) {
            prob_happy = prob_happy*(1-p) + p*(1-prob_happy);
        }
        p = p*(1-p) + (1-p)*p;
        n /= 2;
    }
    cout<<prob_happy;
    return 0;
}