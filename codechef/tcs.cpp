#include <iostream>
using namespace std;

int base(char a)
{
    switch(a)
    {
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        case 'G': return 16;
        default : 
                return a-'0';
    }
    return -1;
}
int main()
{
    int b,i=0;
    long long int p=0;
    string st;
    cin>>st;
    for(char& a:st)
    {   
        b = base(a);
        p= 17*p + b;
    }
    cout<<p;
    return 0;
}