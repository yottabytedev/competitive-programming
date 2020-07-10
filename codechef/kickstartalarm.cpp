#include <bits/stdc++.h>
#define ll long long 
#define mod 1000000007 
using namespace std;

vector<ll> generatearray(ll n,ll x,ll y,ll c,ll d,ll e1,ll e2,ll F)
{
    vector<ll> arr;
    ll x1,y1;
    arr.push_back((x+y)%F);
    for(ll i=1;i<n;i++)
    {
        x1 = ( c * x + d * y + e1 ) % F;
        y1 = ( d * x + c * y + e2 ) % F;
        x = x1;
        y = y1;
        arr.push_back((x+y)%F);
    }
    return arr;
}
vector<vector<ll> > subArray(vector<ll> arr, ll n) 
{ 
    vector<vector<ll> > ans;
    for (ll i=0; i <n; i++) 
    { 
        // Pick ending poll 
        for (ll j=i; j<n; j++) 
        {   
            vector<ll> temp;
            // Prll subarray between current starting 
            // and ending polls 
            for (ll k=i; k<=j; k++) 
                temp.push_back(arr[k]); 
  
            ans.push_back(temp);
        } 
    } 
    return ans;
} 
ll powercalculator(vector<vector<ll> > subarray,ll i)
{
    ll subsize = subarray.size(); 
    ll sum = 0;
    for(ll start = 0;start<subsize;start++)
    {
        for(ll p=0;p<subarray[start].size();p++)
        {
            sum=sum+subarray[start][p]*(pow(p+1,i));
            sum = sum%mod;
        }
    }
    return sum%mod;
}
int main()
{
    ll t;
    cin>>t;
    for(ll i=1;i<=t;i++)
    {
        
        ll n,k,x,y,c,d,e1,e2,F;
        cin>>n>>k>>x>>y>>c>>d>>e1>>e2>>F;
        vector<ll> arr = generatearray(n,x,y,c,d,e1,e2,F);
        vector<vector<ll> > subarray = subArray(arr,n); 
        ll total=0;
        for(ll a=1;a<=k;a++)
        {
            total = (total + powercalculator(subarray,a) ) % mod;
        }
        cout<<"Case #"<<i<<": "<<total<<endl;
    }
    return 0;
}