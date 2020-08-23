#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
ll A[100000000];

void solve(int t){
    cin>>N;
    int count = 0;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    //sort(A,A+N);
    int d,p;
    int answer = 0;

    for(int i=1;i<N;i++){
        d = A[i]-A[i-1];
        if(d == p && i>1) {
            count++;
            answer = max(answer,count);
        } else {
            count = 0;
        }
        p = d;
    }
    answer = min(answer+2,N);
    printf("Case #%d: %d\n",t,answer);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        solve(i);
    }
}