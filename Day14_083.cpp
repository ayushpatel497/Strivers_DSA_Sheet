class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;
    Node(int k,int v){
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    int n;
    unordered_map<int, Node*> mp;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1); 

    LRUCache(int capacity) {
        // Q. LRU Cache
        n = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.count(key)){
            Node *temp = mp[key];
            remove(temp);
            insert(temp);
            return temp -> val;
        }
        return -1;
    }
    void remove(Node *root){
        mp.erase(root -> key);
        Node *prevv = root -> prev;
        Node * nextt = root -> next;
        prevv -> next = nextt;
        nextt -> prev = prevv;
    }

    void insert(Node *root){
        mp[root -> key] = root;
        Node *temp = head -> next;
        head -> next = root;
        root -> next = temp;
        temp -> prev = root;
        root -> prev = head;
    }    
    
    void put(int key, int value) {
        Node *temp = new Node(key, value);
        if(mp.count(key)){
            remove(mp[key]);
        }
        if(mp.size() == n){
            remove(tail -> prev);
        }
        insert(temp);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */