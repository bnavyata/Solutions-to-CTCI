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

bool checkPermutationUsingSort(string s1,string s2) {
	// Time complexity: O(nlogn)
	// Space complexity: O(1)
	if (s1.length() != s2.length()) return false;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	for (int i = 0; i < s1.length(); ++i)
	{
		if (s1[i] != s2[i])
			return false;
	}
	return true;
}

bool checkPermutationUsingMap(string s1, string s2) {
	// Time complexity: O(n)
	// Space complexity: O(n)
	unordered_map<char, int> myMap;
	if (s1.length() != s2.length()) return false;
	for (int i = 0; i < s1.length(); ++i)
		myMap[s1[i]]++;
	for(int i = 0; i < s2.length(); ++i)
	{
		if (myMap.find(s2[i]) == myMap.end())
			return false;
		else {
			if (myMap[s2[i]] == 0) return false;
			if (myMap[s2[i]]>0)
				myMap[s2[i]]--;
		}
			
	}

	return true;
}

int main() {
	string s1 = "navyatabawa";
	string s2 = "banavwayaaa";
	if (checkPermutationUsingSort(s1,s2))
		cout << "String is permutation of another" << endl;
	else
		cout << "String is not permutation of another" << endl;

	getchar();
	return 0;
}