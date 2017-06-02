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
using namespace std;

class Stack
{
public:
	Stack();
	~Stack();
	virtual void Push(int x);
	virtual void Pop();
	bool isEmpty();
	int Peek();
	vector<int> mStackElements;
	int mTop;
};

Stack::Stack()
{
}

Stack::~Stack()
{
}

void Stack::Push(int x)
{
	mStackElements.push_back(x);
	mTop++;
}

void Stack::Pop()
{
	std::cout << "Popping value " << mStackElements[mTop] << std::endl;
	if (!isEmpty())
		mTop--;
	else
		return;
}

bool Stack::isEmpty()
{
	if (mTop == -1)
		return true;
	return false;
}

int Stack::Peek()
{
	if (mTop != -1)
		return mStackElements[mTop];
	return -1;
}

class myQueue {
	Stack myStack1;
	Stack myStack2;

	void Push(int x) {
		if (myStack1.isEmpty()) {
			myStack1.Push(x);
		}
		else {
			while (!myStack1.isEmpty()) {
				myStack2.Push(myStack1.Peek());
				myStack1.Pop();
			}
			while (!myStack2.isEmpty()) {
				myStack1.Push(myStack2.Peek());
				myStack2.Pop();
			}
		}
	}

	void Pop() {
		myStack1.Pop();
	}

	int Peek() {
		return myStack1.Peek();
	}
};

