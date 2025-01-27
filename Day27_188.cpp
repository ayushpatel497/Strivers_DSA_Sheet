#include<bits/stdc++.h>
class TrieNode{
  public:
    unordered_map<char, TrieNode*> children;
    TrieNode(){}
};

int countDistinctSubstrings(string &s)
{
    // Q. Count Distinct Substrings
    //    Write your code here.
    int count = 0;
    TrieNode *root = new TrieNode();
    for(int i = 0; i < s.length(); ++i){
        TrieNode *node = root;
        for(int j = i; j < s.length(); ++j){
            if(!node -> children.count(s[j])){
                count += 1;
                node -> children[s[j]] = new TrieNode();
            }
            node = node -> children[s[j]];
        }
    }
    return count + 1;
}