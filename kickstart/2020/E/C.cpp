#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, A[10000][100],a,b,c;

void solve(int t){
    cin>>N>>a>>b>>c;
    int ta=0,tb=0,tc=0;
    for(int i=1;i<=(N*N);i++){
        for(int j=1;j<=N;j++){
            A[i-1][j-1] = j;
        }
    }
    
    for(int i=0;i<(N*N);i++){
        int pa = A[i][0], pb = A[i][N-1];
        for(int j=0;j<N;j++){
            if(A[i][j]>=pa) ta++;
            if(A[i][N-1-j]>=pb) tb++;
            if(A[i][j] == N) tc++;
            if(ta == a && tb == b && tc == c){
                printf("Case #%d: ",t);

                for(int k=0;k<N;k++){
                    printf("%d ",A[i][k]);
                }
                printf("\n");
                return;
            } 
        }
    }
    printf("Case #%d: IMPOSSIBLE\n",t);
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