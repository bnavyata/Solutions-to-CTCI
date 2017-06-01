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

ListNode* reverseList(ListNode* head) {
	if (!head || !head->next) return head;
	ListNode* node = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return node;
}

int findLength(ListNode* head, ListNode* &tail) {
	ListNode* temp = head;
	int count = 0;
	while (temp->next) {
		temp = temp->next;
		count++;
	}
	tail = temp;
	return count+1;
}

bool intersection(ListNode* head1, ListNode* head2) {
	bool flag = false;
	ListNode* tail1;
	ListNode* tail2;
	int length1 = findLength(head1, tail1);
	int length2 = findLength(head2, tail2);
	if (tail1 != tail2) return false;

	if (length1 > length2) flag = true;
	int diffLength = abs(length1 - length2);
	for (int i = 0; i < diffLength; i++) {
		if (flag) {
			head1 = head1->next;
		}
		else {
			head2 = head2->next;
		}
	}
	while (head1 && head2) {
		if (head1 == head2)
			return true;
		head1 = head1->next;
		head2 = head2->next;
	}

	return false;
}

int main() {
	//617
	ListNode* head1 = new ListNode(6);
	ListNode* first1 = new ListNode(1);
	ListNode* second1 = new ListNode(7);

	//292
	ListNode* head2 = new ListNode(2);
	ListNode* first2 = new ListNode(9);
	ListNode* second2 = new ListNode(2);

	head1->next = first1;
	head1->next->next = second1;

	head2->next = second1;

	bool result = intersection(head1, head2);
	getchar();
	return 0;
}