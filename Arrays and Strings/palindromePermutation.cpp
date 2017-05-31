#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <locale>
#include <sstream>
#include <stdlib.h>
#include <climits>
using namespace std;

void removeSpaces(string &str) {
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
}

bool isPermPalindrome(string s) {
	removeSpaces(s);
	bool isOddCount = false;
	unordered_map<char, int> myMap;
	for (int i = 0; i < s.length(); i++)
		myMap[s[i]]++;
	for (auto it = myMap.begin(); it != myMap.end(); it++) {
		if (it->second % 2 != 0 && isOddCount == false)
			isOddCount = true;
		else if (it->second % 2 != 0 && isOddCount == true)
			return false;
	}
	return true;
}

int main() {
	string s1 = "nav ny av";
	if (isPermPalindrome(s1))
		cout << "string is permutation of a palindrome" << endl;
	else
		cout << "string is not a permutation of a palindrome" << endl;
	getchar();
	return 0;
}