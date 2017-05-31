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

void rotateMatrixClockwise(vector<vector<int>> &matrix){
	reverse(matrix.begin(), matrix.end());
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = i + 1; j < matrix[i].size(); j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}


void rotateMatrixAnticlockwise(vector<vector<int>> &matrix) {
	reverse(matrix[0].begin(), matrix[0].end());
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = i + 1; j < matrix[i].size(); j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}
}

int main() {
	vector<vector<int>> matrix = { {1,2,3},{4,5,6},{7,8,9} };
	rotateMatrixClockwise(matrix);
	getchar();
	return 0;
}