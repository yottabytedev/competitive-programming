#include <bits/stdc++.h>
using namespace std;

// string lexi(vector<string> s){
//     string temp;
// 	for(int i = 0; i < s.size()-1; ++i){
// 		for(int j = i+1; j < s.size(); ++j) {
// 	      if(s[i] > s[j]) {
// 	         temp = s[i];
// 	         s[i] = s[j];
// 	         s[j] = temp;
// 	      }
// 	   }
// 	}
// 	return s[0];
// }

int main() {
	// your code goes here
	int t;
    cin>>t;
	while(t--){
		string s,p;
        cin>>s>>p;
		
		unordered_map<char,int> sr,pr;
		for(char i:p){
			pr[i]++;
		}
		for(char i:s){
			sr[i]++;
		}
		for(auto i:pr){
			sr[i.first] -= i.second;
		}

		string result;
		for(auto i:sr){
			result += string(i.second,i.first);
		}
		sort(result.begin(),result.end());
		
		int l = result.length();
		vector<string> arr(l+1);
		
		for(int i=0;i<l+1;i++){
			arr[i] = result.substr(0,i) + p + result.substr(i,l-i);
		}
        sort(arr.begin(),arr.end());
		string output = arr[0];
		cout<<output<<endl;
	}
	return 0;
}