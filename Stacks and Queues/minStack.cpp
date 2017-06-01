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

class MinStack :public Stack
{
public:
	MinStack();
	~MinStack();
	int Min();
	void Push(int x);
	void Pop();

	vector<int> mMinList;
};

MinStack::MinStack()
{

}


MinStack::~MinStack()
{
}

int MinStack::Min()
{
	if (!isEmpty())
		return mMinList.back();
	return -1;
}

void MinStack::Push(int x)
{
	if (isEmpty())
		mMinList.push_back(x);
	else
	{
		if (x <= mMinList.back())
			mMinList.push_back(x);
	}
	mStackElements.push_back(x);
	cout << "Inserted value: " << x << endl;
	mTop++;
}

void MinStack::Pop()
{
	if (mStackElements[mTop] == mMinList.back())
		mMinList.pop_back();

	if (!isEmpty())
		mTop--;
	else
		return;

}

int main() {

	getchar();
	return 0;
}