/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        // Q. Delete Node in a Linked List
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};