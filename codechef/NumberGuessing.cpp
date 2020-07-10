#include <bits/stdc++.h>
#include <thread> 
#include <chrono>
using namespace std;

string s1("CORRECT");
string s2("TOO_SMALL");
string s3("TOO_BIG");
string s4("WRONG_ANSWER");

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        int n;
        cin>>n;
        int q;
        string test;
        cin.ignore();
        while(n--)
        {
            if(b-a == 1)
            	{q=b;}
            else {q=(a+b)/2;}            
            cout<<q<<endl;
            //this_thread::sleep_for(chrono::seconds(1));           
        	getline(cin,test);
        	//this_thread::sleep_for(chrono::seconds(1));
            if(test.compare(s1)==0 || test.compare(s4)==0 || q>=b)
                {break;}
            else if(test.compare(s2)==0)
                {a = q;
                }
                else if(test.compare(s3)==0)
                    {b = q;}
        }
    }
    return 0;
}