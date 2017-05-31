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

string stringCompression(string str) {
	int i = 0;
	int count;
	string result;
	for (int i = 0; i < str.length();)
	{
		char temp = str[i];
		result.push_back(temp);
		count = 0;
		while (str[i] == temp) {
			count++;
			i++;
		}

		result.append(to_string(count));
	}
	return result;
}

int main() {
	string s = "aabccccaaa";
	string result = stringCompression(s);
	cout << result << endl;
	getchar();
	return 0;
}