#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll i,n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		i=n-1;
		ll l=0,r=n-1;
		ll flag=0;
		vector<ll> vec;
		while(i>=0)
		{
			// cout<<i<<" "<<l<<" "<<r<<"af\n";
			if(a[r]==b[i] && flag==0)
			{
				r--;
				i--;
				continue;
			}
			if(a[r]!=b[i] && flag==1)
			{
				r++;
				i--;
				continue;
			}
 
			if(a[l]!=a[r])
			{
				a[l]=!a[l];
				vec.push_back(1);
				if(i==0)
					break;
			}
			vec.push_back(i+1);
			if(l<=r)
			{
				ll temp=l;
				l=r;
				r=temp+1;
			}
			else
			{
				ll temp=l;
				l=r;
				r=temp-1;
			}
			flag=!flag;
			i--;
		}
		cout<<vec.size()<<" ";
		for(i=0;i<vec.size();i++)
		{
			cout<<vec[i]<<" ";
		}
		cout<<"\n";
	}
}