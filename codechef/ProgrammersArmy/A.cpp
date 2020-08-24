#include <bits/stdc++.h>
using namespace std;

void solve()
{
    char ch;
    int hr,minute;
    cin>>hr>>ch>>minute;

    hr%=12;
 

	float hr_ang = 30*hr+0.5*minute; 
	float min_ang = 6 * minute; 

	float diff = abs(hr_ang - min_ang);  
	diff = min(360 - diff, diff);

    cout<<diff<<" degree\n";

}

int main()
{

  int tc;
  cin>>tc;
  while(tc--)
  {
    solve();
  }
  return 0;
}