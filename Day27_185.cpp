class TrieNode{
  public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode(){
        isWord = false;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        // Q. Implement Trie (Prefix Tree)
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(char c : word){
            if(!node -> children.count(c)){
                node -> children[c] = new TrieNode();
            }
            node = node -> children[c];
        }
        node -> isWord = true;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        for(char c : word){
            if(!node -> children.count(c)){
                return false;
            }
            node = node -> children[c];
        }
        return node -> isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(char c : prefix){
            if(!node -> children.count(c)){
                return false;
            }
            node = node -> children[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */