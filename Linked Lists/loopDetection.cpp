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

ListNode* loopDetection(ListNode* head) {
	ListNode* slow_ptr = head;
	ListNode* fast_ptr = head; 
	while (fast_ptr && fast_ptr->next) {
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;
		if (slow_ptr == fast_ptr)
			break;
	}

		slow_ptr = head;
		while (slow_ptr != fast_ptr) {
			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next;
		}
	return slow_ptr;
}

int main() {
	//617
	ListNode* head1 = new ListNode(6);
	ListNode* first1 = new ListNode(1);
	ListNode* second1 = new ListNode(7);
	ListNode* third1 = new ListNode(3);

	head1->next = first1;
	head1->next->next = second1;
	head1->next->next->next = third1;
	head1->next->next->next = first1;

	ListNode* result = loopDetection(head1);
	getchar();
	return 0;
}