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

string URLify(string &s, int trueLength) {
	int newLength = s.length();
	int j = newLength - 1;
	int i = trueLength - 1;
	for (; i >= 0; i--) {
		if (s[i] == ' ') {
			s[j--] = '0';
			s[j--] = '2';
			s[j--] = '%';
		}
		else {
			s[j] = s[i];
			j--;
		}
	}	
	return s;
}

int main() {
	string s1 = "nav yata bawa    ";
	string result = URLify(s1,13);
	cout << result << endl;
	getchar();
	return 0;
}