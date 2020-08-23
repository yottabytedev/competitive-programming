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
                dp[i-2] = M[i] - M[i-1];
            }
        }

        memset(k,0,sizeof(k[0])*N);
        long long initial = 1, end = *max_element(M+1,M+N+1);
        long long doptimal = (end+initial)/2;
        long long caseend = end;
        long long ksum = INT_MAX, answer = INT_MAX;

        for(long long c=0; c < log(caseend)+1; c++){
            ksum = 0;
            for(int i=0; i<N-1; i++){
                k[i] = ceil(dp[i]/doptimal) - 1;
                ksum += (k[i]>0?k[i]:0);
            }
            cout<<"doptimal "<<doptimal<< " ksum "<<ksum<<endl;
            if(ksum>K){
                initial = doptimal;
            } else {
                end = doptimal;
                answer = min(answer,doptimal);
            }
            doptimal = (initial + end)/2;
        }

        printf("Case #%d: %d\n",cs,answer);
    }
}