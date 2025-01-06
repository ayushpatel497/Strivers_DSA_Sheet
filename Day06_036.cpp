//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

void printList(Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
    printf("\n");
}


// } Driver Code Ends
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        // Your code here
        // Q. Flattening a Linked List
        if(!root || !root -> next){
            return root;
        }
        Node* mergedRoot = flatten(root->next);
        root = mergeTwoLists(root, mergedRoot);
        return root;
    }
    
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node *root = new Node(-1);
        Node *curr = root;
        while(list1 && list2){
            if(list1 -> data <= list2 -> data){
                curr -> bottom = list1;
                list1 = list1 -> bottom;
            }
            else{
                curr -> bottom = list2;
                list2 = list2 -> bottom;
            }
            curr -> next = NULL;
            curr = curr -> bottom;
        }
        if(list1){
            curr -> bottom = list1;
        }
        if(list2){
            curr -> bottom = list2;
        }
        
        if(root -> bottom){
            root -> bottom -> next = NULL;
        }

        return root -> bottom;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        vector<int> work;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            work.push_back(number);
        }
        n = work.size();

        Node *head = NULL;
        Node *pre = NULL;

        for (int i = 0; i < n; i++) {
            int m = work[i] - 1;
            int data;
            cin >> data;
            Node *temp = new Node(data);
            if (head == NULL) {
                head = temp;
                pre = temp;
            } else {
                pre->next = temp;
                pre = temp;
            }

            Node *preB = temp;
            for (int j = 0; j < m; j++) {
                int temp_data;
                cin >> temp_data;
                Node *tempB = new Node(temp_data);
                preB->bottom = tempB;
                preB = tempB;
            }
        }

        Solution ob;
        Node *root = ob.flatten(head);
        printList(root);
    }
    return 0;
}

// } Driver Code Ends