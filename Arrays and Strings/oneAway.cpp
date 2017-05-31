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
#include <cstdlib>
using namespace std;

bool oneEditReplace(string s1, string s2) {
	bool isDiff = false;
	for (int i = 0; i < s1.length(); i++) {
		if (s1[i] != s2[i]) {
			if (isDiff)
				return false;
			isDiff = true;
		}
		return true;
	}
}

bool oneEditInsert(string longer, string shorter) {
	int i = 0;
	int j = 0;
	while (i < longer.length() && j < shorter.length()) {
		if (longer[i] != shorter[j]) {
			if (i != j)
				return false;
			i++;
		}
		else {
			i++;
			j++;
		}
	}
	return true;
}

bool isOneAway(string s1, string s2) {
	string longer;
	string shorter;
	int lengthDiff = s1.length() - s2.length();
	if (abs(lengthDiff) > 1) return false;

	if (s1.length() == s2.length()) {
		return oneEditReplace(s1, s2);
	}
	else if (s1.length() > s2.length()) {
		longer = s1;
		shorter = s2;
		return oneEditInsert(longer, shorter);
	}
	else if (s1.length() < s2.length()) {
		longer = s2;
		shorter = s1;
		return oneEditInsert(longer, shorter);
	}
	return true;
}

int main() {
	string s1 = "nav";
	string s2= "navya";
	if (isOneAway(s1,s2))
		cout << "strings are one step away" << endl;
	else
		cout << "strings are not one step away" << endl;
	getchar();
	return 0;
}