/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // Q. Copy List with Random Pointer
        if(!head){
            return head;
        }
        Node *temp;

        temp = head;
        while(temp){
            Node *nextElement = temp -> next;
            Node *copy = new Node(temp -> val);  
            copy -> next = nextElement;  
            temp -> next = copy;         
            temp = nextElement;         
        }

        temp = head;
        while(temp){
            Node *copyNode = temp -> next;    
            if(temp -> random){
                copyNode -> random = temp -> random -> next; 
            }
            temp = temp -> next -> next;   
        }
        
        temp = head;
        Node *dummyNode = new Node(-1);
        Node *copyTemp = dummyNode;             
        while(temp){
            copyTemp -> next = temp -> next;
            copyTemp = copyTemp -> next;
            temp -> next = temp -> next -> next;
            temp = temp -> next;
        }
        
        return dummyNode -> next;   
    }

};