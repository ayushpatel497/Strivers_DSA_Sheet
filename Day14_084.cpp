class Node{
public:
    int key;
    int val;
    int count;
    Node *prev;
    Node *next;
    Node(int key_, int val_){
        key = key_;
        val = val_;
        count = 1;
    }
};

class List{
public:
    int size;
    Node* head;
    Node* tail;
    List(){
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }

    void addFront(Node *root){
        Node *temp = head -> next;
        head -> next = root;
        root -> next = temp;
        temp -> prev = root;
        root -> prev = head;
        size += 1;
    }

    void removeNode(Node *root){
        Node *prevv = root -> prev;
        Node *nextt = root -> next;
        prevv -> next = nextt;
        nextt -> prev = prevv;
        size -= 1;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;

    LFUCache(int capacity) {
        // Q. LFU Cache
        maxSizeCache = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqListMap(Node *root){
        keyNode.erase(root -> key);
        freqListMap[root -> count] -> removeNode(root);
        if(root -> count == minFreq && freqListMap[root -> count] -> size == 0){
            minFreq += 1;
        }
        List *nextHigherFreqList = new List();
        if(freqListMap.count(root -> count + 1)){
            nextHigherFreqList = freqListMap[root -> count + 1];
        }
        root -> count += 1;
        nextHigherFreqList -> addFront(root);
        freqListMap[root -> count] = nextHigherFreqList;
        keyNode[root -> key] = root;
    }
    
    int get(int key) {
        if(keyNode.count(key)){
            Node *temp = keyNode[key];
            int val = temp -> val;
            updateFreqListMap(temp);
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(maxSizeCache == 0){
            return;
        }
        if(keyNode.count(key)){
            Node *temp = keyNode[key];
            temp -> val = value;
            updateFreqListMap(temp);
        }
        else{
            if(currSize == maxSizeCache){
                List *list = freqListMap[minFreq];
                keyNode.erase(list -> tail -> prev -> key);
                freqListMap[minFreq] -> removeNode(list -> tail -> prev);
                currSize -= 1;
            }
            currSize += 1;
            minFreq = 1;
            List *listFreq = new List();
            if(freqListMap.count(minFreq)){
                listFreq = freqListMap[minFreq];
            }
            Node *temp = new Node(key, value);
            listFreq -> addFront(temp);
            keyNode[key] = temp;
            freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */