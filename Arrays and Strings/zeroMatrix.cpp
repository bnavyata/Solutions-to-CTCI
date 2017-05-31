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

void zeroMatrix(vector<vector<int>> &matrix) {
	vector<bool> row(matrix.size());
	vector<bool> col(matrix[0].size());

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++) {
			if (matrix[i][j] == 0) {
				row[i] = true;
				col[j] = true;
			}
		}
	}
	for (int i = 0; i < matrix.size(); i++) {
		if (row[i]) {
			for (int j = 0; j < matrix[0].size(); j++) {
				matrix[i][j] = 0;
			}
		}
	}
	for (int j = 0; j < matrix[0].size(); j++) {
		if (col[j]) {
			for (int i = 0; i < matrix.size(); i++) {
				matrix[i][j] = 0;
			}
		}
	}
}

int main() {
	vector<vector<int>> matrix = { { 1,0,3 },{ 4,5,6 },{ 7,8,0 } };
	zeroMatrix(matrix);
	getchar();
	return 0;
}