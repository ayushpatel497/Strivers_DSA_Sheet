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
    bool isPalindrome(ListNode* head) {
        // Q. Palindrome Linked List
        ListNode *slow = head, *fast = head  -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = reverseList(slow -> next);
        slow = slow -> next;
        fast = head;
        while(slow){
            if(slow -> val != fast -> val){
                reverseList(slow);
                return false;
            }
            slow = slow -> next;
            fast = fast -> next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) 
            return head;
        ListNode *prev = NULL, *curr = head, *next = head;
        while(curr){
            next = next -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};