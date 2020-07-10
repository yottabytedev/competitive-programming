#include<bits/stdc++.h>
#include<math.h>
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define fo(i,j,l) for(int i=j;i<=l;i++)
#define fd(i,j,l) for(int i=j;i>=l;i--)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{  ios_base::sync_with_stdio(0); 
   cin.tie(NULL);
   double h,l,pl,ph;
   cin>>h>>l; 
   double x;
   pl = pow(l,2);
   ph = pow(h,2);
   x = double((pl-ph)/(2*h));
   cout<<setprecision(13)<<fixed<<x;
   return 0;            
}
