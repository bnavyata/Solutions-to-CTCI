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

ListNode* partition(ListNode* head, int k) {
	ListNode* front = head;
	ListNode* back = head;

	while (head) {
		ListNode* next = head->next;
		if (head->mVal < k) {
			head->next = front;
			front = head;
		}
		else {
			back->next = head;
			back = head;
		}
		head = next;
	}
	back->next = NULL;
	return front;
}

int main() {
	ListNode* head = new ListNode(4);
	ListNode* first = new ListNode(1);
	ListNode* second = new ListNode(5);
	ListNode* third = new ListNode(3);
	head->next = first;
	head->next->next = second;
	head->next->next->next = third;
	int k = 5;
	head = partition(head,k);
	getchar();
	return 0;
}