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

int kToLast(ListNode* head, int k) {
	ListNode* slow_ptr = head;
	ListNode* fast_ptr = head;

	for (int i = 0; i < k; i++)
		fast_ptr = fast_ptr->next;
	while (fast_ptr  && slow_ptr) {
		fast_ptr = fast_ptr->next;
		slow_ptr = slow_ptr->next;
	}
	return slow_ptr->mVal;
	
}

int main() {
	ListNode* head = new ListNode(2);
	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(4);
	ListNode* third = new ListNode(4);
	head->next = first;
	head->next->next = second;
	head->next->next->next = third;
	int k = 2;
	int result = kToLast(head, k);
	cout << result << " is the " << k << " element of the list" << endl;

	getchar();
	return 0;
}