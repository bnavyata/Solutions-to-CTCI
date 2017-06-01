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

ListNode* sumLists(ListNode* head1Reversed, ListNode* head2Reversed) {
	ListNode* head1 = reverseList(head1Reversed);
	ListNode* head2 = reverseList(head2Reversed);
	ListNode* result = new ListNode(0);
	ListNode* resultHead = result;
	int carry = 0;
	while (head1 && head2) {
		int sum = head1->mVal + head2->mVal + carry;
		carry = sum / 10;
		int rem = sum % 10;
		ListNode* node = new ListNode(rem);
		result->next = node;
		result = result->next;
		head1 = head1->next;
		head2 = head2->next;
	}
	while (head1 || head2) {
		int sum = head1 ? head1->mVal + carry : head2->mVal + carry;
		carry = sum / 10;
		int rem = sum % 10;
		ListNode* node = new ListNode(rem);
		result->next = node;
		result = result->next;
		if (head1)
			head1 = head1->next;
		if (head2)
			head2 = head2->next;
	}
	return reverseList(resultHead->next);
}

int main() {
	//617
	ListNode* head1 = new ListNode(6);
	ListNode* first1 = new ListNode(1);
	ListNode* second1 = new ListNode(7);

	//295
	ListNode* head2 = new ListNode(2);
	ListNode* first2 = new ListNode(9);
	ListNode* second2 = new ListNode(5);

	head1->next = first1;
	head1->next->next = second1;

	head2->next = first2;
	head2->next->next = second2;

	//912
	ListNode* result = sumLists(head1, head2);
	getchar();
	return 0;
}