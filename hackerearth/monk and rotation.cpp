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
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> A(n);
		for(auto &a:A){
			cin>>a;
		}
		for(int i=n-(k%n),j=0;j<n;i++,j++){
			cout<<A[i%n]<<" ";
		}
		cout<<endl;
	}
	return 0;
}