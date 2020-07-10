#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() { //subarrays
  vector < int > A {
    1,
    2,
    4
  };
  vector < int > g;
  int n1 = A.size();

  for (int i = 0; i < n1; i++) {
    for (int j = i; j < n1; j++) {
      g.push_back(*max_element(A.begin() + i, A.begin() + j + 1));
    }
  }


  //product of divisors
  for (int j = 0; j < g.size(); j++) {
    long long int pr = 1;
    long long int n = g[j];
    for (int i = 1; i <= n; i++) {
      if (n % i == 0) {
          pr *= i;
        }
      }
    g[j] = pr % 1000000007;
  }
  // sort
  sort(g.begin(), g.end(),greater <>());

  for(int i = 0;i<g.size();i++)
  {cout<<g[i]<<" ";}

  
  return 0;
}