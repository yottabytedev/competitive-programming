#include <bits/stdc++.h>
using namespace std;

int T,N,K;
long long M[1],dp[1],k[1];

int main(){
    cin>>T;
    for(int cs=1;cs<=T;cs++){
        cin >> N >> K;
        memset(M,0,sizeof(M[0])*(N+1));
        memset(dp,0,sizeof(dp[0])*(N));
        for(int i=1;i<=N;i++){
            cin>>M[i];
            if(i>1){
                dp[i-1] = M[i] - M[i-1];
            }
        }

        long long initial = 1, end = 1e+9;
        long long doptimal = (end+initial)/2;
        memset(k,0,sizeof(k[0])*N);
        long long ksum = INT_MAX;
        while(ksum>K){
            ksum = 0;
            for(int i=0; i<N; i++){
                k[i] = ceil(dp[i]/doptimal) - 1;
                ksum += k[i];
            }
            if(ksum>K){
                initial = doptimal;
            } else {
                break;
            }
            doptimal = (initial + end)/2;
        }

        printf("Case #%d: %d\n",cs,doptimal);
    }
}