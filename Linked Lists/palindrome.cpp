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

bool isPalindrome(ListNode* head) {
	ListNode* reversedHead = reverseList(head);
	while (head) {
		if (head->mVal != reversedHead->mVal)
			return false;
		head = head->next;
		reversedHead = reversedHead->next;
	}
	return true;
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

	head2->next = first2;
	head2->next->next = second2;

	bool result1 = isPalindrome(head1);
	bool result2 = isPalindrome(head2);
	getchar();
	return 0;
}