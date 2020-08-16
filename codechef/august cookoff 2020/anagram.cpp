#include <string>
#include <iostream>
using namespace std;

void anagram(std::string &word, int n)
{
	if (n <= 0) {
		std::cout << word << "\n";
		return;
	}

	if (word[n] < 'a' or word[n] > 'z') {
		anagram(word, n-1);
		return;
	}

	int i;
	for (i = n; i >= 0; --i) {
		if (word[i] < 'a' or word[i] > 'z')
			continue;

		char tmp = word[i];
		word[i] = word[n];
		word[n] = tmp;
		anagram(word, n-1);
	}
}

void print_anagrams(const std::string &w)
{
	std::string word = w;
	anagram(word, word.length()-1);
}

int main(){
    string word;
    cin>>word;
    print_anagrams(word);
}