/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Q. Add Two Numbers
        ListNode *head = new ListNode(0);
        ListNode *tail = head;
        int carry = 0;
        while(l1 || l2 || carry){
            int num1 = l1 ? l1 -> val : 0;
            int num2 = l2 ? l2 -> val : 0;
            int sum = num1 + num2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            tail -> next = new ListNode(digit);
            tail = tail -> next;
            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;
        }

        return head -> next;
    }
};