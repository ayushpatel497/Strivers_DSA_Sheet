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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Q. Intersection of Two Linked Lists
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrA != ptrB) { 
            ptrA = ptrA ? ptrA -> next : headB;
            ptrB = ptrB ? ptrB -> next : headA;
        }
        return ptrA;
    }
};