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

struct ListNode {
	int mVal;
	ListNode* next;

	ListNode(int val) {
		mVal = val;
		next = NULL;
	}
};

void deleteMiddle(ListNode* node) {

	ListNode* temp = node->next;
	*node = *node->next;
	delete temp;
}

int main() {
	ListNode* head = new ListNode(2);
	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(4);
	head->next = first;
	head->next->next = second;
	deleteMiddle(first);
	getchar();
	return 0;
}