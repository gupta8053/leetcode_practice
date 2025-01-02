#include <iostream>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *dummy = new ListNode();
    int carry = 0;
    ListNode *cur = dummy;
    while (l1 || l2 || carry) {
      int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = s / 10;
      cur->next = new ListNode(s % 10);
      cur = cur->next;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }

    return dummy->next;
  }
};

// Helper function to print the linked list
void printList(ListNode *node) {
  while (node != nullptr) {
    std::cout << node->val << " ";
    node = node->next;
  }
  std::cout << std::endl;
}

int main() {
  // Creating the first linked list: 2 -> 4 -> 6
  ListNode *l1 = new ListNode(2);
  l1->next = new ListNode(4);
  l1->next->next = new ListNode(6);

  // Creating the second linked list: 5 -> 6 -> 4
  ListNode *l2 = new ListNode(5);
  l2->next = new ListNode(6);
  l2->next->next = new ListNode(4);

  Solution solution;
  ListNode *result = solution.addTwoNumbers(l1, l2);

  // Printing the result linked list
  printList(result); // Output should be: 7 0 8

  return 0;
}
