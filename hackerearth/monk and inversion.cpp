/*
// Sample code to perform I/O:

#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;										// Reading input from STDIN
	cout << "Input number is " << num << endl;		// Writing output to STDOUT
}

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int>> A(n, vector<int> (n));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin>>A[i][j];
			}
		}

		int count=0;
		for(int p=0;p<n;p++){
			for(int q=0;q<n;q++){
				for(int i=0;i<=p;i++){
					for(int j=0;j<=q;j++){
						if(A[i][j]>A[p][q]) count++;
					}
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
