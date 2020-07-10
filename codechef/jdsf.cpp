#include <iostream>
using namespace std;
#define lli long long int 

lli findNth(lli n) 
{ 
    lli count = 0; 
  
    for (lli curr = 18;; curr++) { 
  
        
        int sum = 0; 
        for (int x = curr; x > 0; x = x / 10) 
            sum = sum + x % 10; 
  
        
        if (sum%10 == 0) 
            count++; 
  
        if (count == n) 
            return curr; 
    } 
    return -1; 
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        cout<<findNth(n)<<endl;
        
    }
    
    return 0;
}