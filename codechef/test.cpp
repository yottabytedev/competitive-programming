#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int d;
        cin>>d;
        char s[d];

        int i,present=0,si[d];
        for(i=0;i<d;i++)
        {
            cin>>s[i];
            if(s[i]=='A')
            {
                si[i]=0;
            }
            else
            {
                si[i]=1;
                present++;
            }
        }


        int a = 0.75 * d;
        if( float(a)<(0.75*d) )
        { a = int(a) + 1;}

        
        int proxy=0;
        for(i=2;i<d-2;i++)
        {
            if(si[i]==0 && (si[i-1]==1 || si[i-2]==1) && (si[i+1]==1 || si[i+2]==1))
            {
                proxy++;
            }
        }

        if(present >= a)
        {cout<<"0"<<endl;}
        else if( proxy < (a-present) )
                {
                    cout<<'-1'<<endl;
                }
               else
               {
                   cout<<(a-present)<<endl;
               } 
    }
    
    return 0;
}