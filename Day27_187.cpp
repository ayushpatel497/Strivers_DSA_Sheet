#include <bits/stdc++.h> 
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

    bool checkPrefixExists(string word){
        TrieNode *node = root;
        for(char c : word){
            if(node -> children.count(c)){
                node = node -> children[c];
                if(!node -> isWord){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Q. Complete String
    // Write your code here.
    Trie trie;
    for(auto str : a){
        trie.insert(str);
    }
    string longest = "";
    for(auto str : a){
        if(trie.checkPrefixExists(str)){
            if(str.length() > longest.length()){
                longest = str;
            }
            else if(str.length() == longest.length() && str < longest){
                longest = str;
            }
        }
    }
    return longest == "" ? "None" : longest;
}