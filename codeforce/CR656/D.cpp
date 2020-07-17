#include <bits/stdc++.h>
#define lli long long int
using namespace std;

lli matcher(string s,char c) {
    lli counter=0;
    for (lli i = 0;i<s.length();i++) {
        if (s[i] != c) {
            counter++;
        }
    }
    return counter;
}

lli goodString(string s, char c) {
    lli n = s.length();
    if (n == 1) {
        if (s[0] == c) 
            return 0;
        return 1;
    }
    lli counter_firsthalf = matcher(s.substr(0,n/2),c);
    lli counter_secondhalf = matcher(s.substr(n/2,n/2),c);
    return min((counter_firsthalf + goodString(s.substr(n/2,n/2),c+1)), (counter_secondhalf + goodString(s.substr(0,n/2),c+1)));
    // if (counter_firsthalf != 0 && counter_secondhalf != 0) {
    //     if (counter_firsthalf <= counter_secondhalf) {
    //         return (counter_firsthalf + goodString(s.substr(n/2,n/2),c+1));
    //     } else {
    //         return (counter_secondhalf + goodString(s.substr(0,n/2),c+1));
    //     }
    // } else if (counter_firsthalf == 0) {
    //     return goodString(s.substr(n/2,n/2),c+1);
    // } else
    // {
    //     return goodString(s.substr(0,n/2),c+1);
    // }
    

}
int main()
{
    lli t;
    cin>>t;
    while(t--) {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        cout<<goodString(s,'a')<<endl;
    }
    return 0;
}