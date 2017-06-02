#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <locale>
#include <sstream>
#include <stdlib.h>
#include <climits>
#include <cstdlib>
#include <stack>
using namespace std;

void sortedStack(stack<int> &myStack) {
	stack<int> tempStack;
	int x = myStack.top();
	tempStack.push(x);
	myStack.pop();

	while (!myStack.empty()) {
		if (myStack.top() > tempStack.top()) {
			tempStack.push(myStack.top());
			myStack.pop();
		}
		else {
			int temp = myStack.top();
			myStack.pop();
			int count = 0;
			while (!tempStack.empty() && tempStack.top() > temp) {
				myStack.push(tempStack.top());
				count++;
				tempStack.pop();
			}
			tempStack.push(temp);
			while (count --) {
				tempStack.push(myStack.top());
				myStack.pop();
			}
		}
	}
	while (!tempStack.empty()) {
		myStack.push(tempStack.top());
		tempStack.pop();
	}
}

int main() {
	stack<int> test;
	test.push(4);
	test.push(6);
	test.push(3);
	test.push(5);
	test.push(8);
	sortedStack(test);
	getchar();
	return 0;
}