class TrieNode {
public:
    TrieNode* children[2];
    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(int num) {
        TrieNode *node = root;
        for (int bit = 31; bit >= 0; --bit) {
            int currBit = (num >> bit) & 1;
            if (!node -> children[currBit]) {
                node -> children[currBit] = new TrieNode();
            }
            node = node -> children[currBit];
        }
    }
    int maxXOR(int num) {
        TrieNode *node = root;
        int answer = 0;
        for (int bit = 31; bit >= 0; --bit) {
            int currBit = (num >> bit) & 1;
            if (node -> children[1 - currBit]) {
                answer |= (1 << bit);
                node = node -> children[1 - currBit];
            } else {
                node = node -> children[currBit];
            }
        }
        return answer;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        // Q. Maximum XOR of Two Numbers in an Array
        Trie trie;
        for (auto num : nums) {
            trie.insert(num);
        }
        int answer = 0;
        for (auto num : nums) {
            answer = max(answer, trie.maxXOR(num));
        }
        return answer;
    }
};
