#include <bits/stdc++.h> 
class TrieNode{
  public:
    unordered_map<char, TrieNode*> children;
    int countEndWith;
    int countPrefix;
    TrieNode(){}
};

class Trie{
    TrieNode *root;
    public:

    Trie(){
        // Q. Implement Trie II
        // Write your code here.
        root = new TrieNode();
    }

    void insert(string &word){
        // Write your code here.
        TrieNode* node = root;
        for(char c : word){
            if(!node -> children.count(c)){
                node -> children[c] = new TrieNode();
            }
            node = node -> children[c];
            node -> countPrefix += 1;
        }
        node -> countEndWith += 1;
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
        TrieNode *node = root;
        for(char c : word){
            if(!node -> children.count(c)){
                return 0;
            }
            node = node -> children[c];
        }
        return node -> countEndWith;
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        TrieNode *node = root;
        for(char c : word){
            if(!node -> children.count(c)){
                return 0;
            }
            node = node -> children[c];
        }
        return node -> countPrefix;
    }

    void erase(string &word){
        // Write your code here.
        TrieNode* node = root;
        for(char c : word){
            if(!node -> children.count(c)){
                return ;
            }
            node = node -> children[c];
            node -> countPrefix -= 1;
        }
        node -> countEndWith -= 1;
    }
};
