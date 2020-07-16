/* Extended version of power function 
that can work for float x and negative y*/
#include <bits/stdc++.h> 
using namespace std; 

double power(double x, long long int y) 
{ 
	double temp; 
	if(y == 0) 
		return 1; 
	temp = power(x, y / 2); 
	if (y % 2 == 0) 
		return temp * temp; 
	else
	{ 
		if(y > 0) 
			return x * temp * temp; 
		else
			return (temp * temp) / x; 
	} 
} 

// Driver Code 
int main() 
{ 
	double x = 2.0; 
	long long int y = 214748364; 
	cout << power(x, y); 
	return 0; 
} 

// This is code is contributed 
// by rathbhupendra 
