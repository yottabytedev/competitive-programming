#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, A[100000],a,b,c;

void solve(int t){
    cin>>N>>a>>b>>c;
    if((a+b-c)>N || (c>a) || (c>b) || (a+b-c)<0 || (c<0) || (N>1 && a==1 && b==1 && c==1)) {
        printf("Case #%d: IMPOSSIBLE\n",t);
        return;
    }
    
    printf("Case #%d: ",t);

    int index = 0;
    //  Andre
    for(int j=0;j<a-c;j++){
        printf("%d ",N-1);
    }
    if(c==1 && a>c){
        for(int j=0;j<(N-a-b+c);j++){
            printf("%d ",N-2);
        }
    }
    printf("%d ",N);
    if(c>1){
            for(int j=0;j<(N-a-b+c);j++){
                printf("%d ",N-2);
        }
    }
    // Common
    for(int j=0; j<c-1 ;j++){
        printf("%d ",N);
    }
    // Extra
    if(c==1 && a==c){
        for(int j=0;j<(N-a-b+c);j++){
            printf("%d ",N-2);
        }
    }   
    // Sule
    for(int i=0;i<b-c;i++){
        printf("%d ",N-1);
    }
    printf("\n");
    // memset(A,0,N*4);
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