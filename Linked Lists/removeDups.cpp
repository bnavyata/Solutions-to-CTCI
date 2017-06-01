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

ListNode* removeDups(ListNode* head) {
	if (!head) return head;
	ListNode* temp = head;
	unordered_set<int> mySet;
	ListNode* prev = NULL;
	while (temp) {
		if (mySet.find(temp->mVal) != mySet.end()) {
			prev->next = temp->next;
		}
		else {
			mySet.insert(temp->mVal);
			prev = temp;
		}	
		temp = temp->next;
	}
	return head;
}

int main() {
	ListNode* head = new ListNode(2);
	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(4);
	ListNode* third = new ListNode(4);
	head->next = first;
	head->next->next = second;
	head->next->next->next = third;
	head = removeDups(head);

	getchar();
	return 0;
}