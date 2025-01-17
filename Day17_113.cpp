/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Q. Vertical Order Traversal of a Binary Tree
        vector<vector<int>> answer;
        if(!root){
            return answer;
        }
        queue<pair<TreeNode *, pair<int, int>>> nodeLineQueue;
        map<int, map<int, multiset<int>>> nodeMap;
        nodeLineQueue.push({root, {0, 0}});
        while(!nodeLineQueue.empty()){
            auto iterator = nodeLineQueue.front();
            nodeLineQueue.pop();
            TreeNode *currNode = iterator.first;
            int lineNumber = iterator.second.first;
            int levelNumber = iterator.second.second;
            nodeMap[lineNumber][levelNumber].insert(currNode -> val);
            if(currNode -> left){
                nodeLineQueue.push({currNode -> left, {lineNumber - 1, levelNumber + 1}});
            }
            if(currNode -> right){
                nodeLineQueue.push({currNode -> right, {lineNumber + 1, levelNumber + 1}});
            }
        }
        for(auto lineValue : nodeMap){
            vector<int> column;
            for(auto levelValue : lineValue.second){
                column.insert(column.end(), levelValue.second.begin(), levelValue.second.end());
            }
            answer.push_back(column);
        }
        return answer;
    }
};