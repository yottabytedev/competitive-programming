#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
 
using namespace std;
 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define lli long long int
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(NULL);
    lli n,i,zero=0;
    int x,y;
    cin>>n>>x>>y;
    lli a[n];
    REP(i,n) cin>>a[i];
    REP(i,n) 
    {
        temp = min_element(a+max(zero,i-x),a+min(i+y,n-1));
        if(a[i]==*temp) 
        {cout<<i+1; break;}
    }
    return 0;
}