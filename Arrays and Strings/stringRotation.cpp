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

bool isSubstring(string s1, string s2) {
	if (strstr(s2.c_str(), s1.c_str())== NULL) {
		return false;
	}
	return true;
}

bool isRotation(string s1, string s2) {
	string s1s1 = s1 + s1;
	return isSubstring(s2, s1s1);
	return true;
}

int main() {
	string s1 = "waterbottle";
	string s2 = "erbottlewat";
	if (isRotation(s1, s2))
		cout << "string is a rotation" << endl;
	else
		cout << " string is not a rotation" << endl;
	getchar();
	return 0;
}