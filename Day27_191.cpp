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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        // Q. Maximum XOR With an Element From Array
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> offlineQueries;
        int querySize = queries.size();
        for(int index = 0; index < querySize; ++index){
            offlineQueries.push_back({queries[index][1], {queries[index][0], index}});
        }
        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> answer(querySize, 0);
        int index = 0;
        int n = nums.size();
        Trie trie;
        for(int query = 0; query < querySize; ++query){
            int m = offlineQueries[query].first;
            int x = offlineQueries[query].second.first;
            int qIndex = offlineQueries[query].second.second;
            while(index < n && nums[index] <= m){
                trie.insert(nums[index]);
                index += 1;
            }
            if(index == 0){
                answer[qIndex] = -1;
            }
            else{
                answer[qIndex] = trie.maxXOR(x);
            }
        }
        return answer;
    }
};