#include <bits/stdc++.h>
#define ll long long
#define fors(i,a,b) for(long long i=a;i<b;i++)
using namespace std;

vector<int> divisors(int n) 
{ 
    // Vector to store half of the divisors 
    vector<int> v; 
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i==0) 
        { 
            if (n/i == i)
            	// check if divisors are equal 
                //printf("%d ", i);          
                v.push_back(i); 

            else
            { 
                //printf("%d ", i); 
                  v.push_back(i); 

                // push the second divisor in the vector 
                v.push_back(n/i); 
            } 
        } 
    } 
  
    // The vector will be printed in reverse 
    // for (int i=v.size()-1; i>=0; i--) 
    //     printf("%d ", v[i]); 
    return v;
} 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<int> arr;
		ll temp;
		map<int,int> ct;
		map<int,int> re;
		fors(i,0,n) {cin>>temp; 
			arr.push_back(temp);
			if(ct.find(temp)==ct.end())
			{ct.insert({temp,0});}
			
			auto it = re.find(temp);
			if(it != re.end())
			{(it->second) = it->second + 1;}
			else {re.insert(make_pair(temp,1));
				}
			
		}
		ll mx = 0;
		fors(i,0,n)
		{
			vector<int> f = divisors(arr[i]);
			for(auto l:f)
			{
				//cout<<i<<" ";
				map<int,int>::iterator t2 = ct.find(l);
				if(t2 !=ct.end())
				{	ct[l]++;
					int p = ct[l];
					cout<<p;
					if(p > mx) {mx = p;}
					if(re[l]>1)
					{
						re[l]--;
					}
					else
					{
						re.erase(l);
						ct.erase(l);
					}
				}
			}
		}
		cout<<(mx)<<endl;
	}
	return 0;
}