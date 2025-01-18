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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        // Q. Binary Tree Zigzag Level Order Traversal
        if(!root){
            return {};
        }

        vector<vector<int>> answer;
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        bool flag = true;
        while(!nodeQueue.empty()){
            int size = nodeQueue.size();
            vector<int> levelNodes;
            for(int nodes = 0; nodes < size; ++nodes){
                TreeNode *curr = nodeQueue.front();
                nodeQueue.pop();
                levelNodes.push_back(curr -> val);
                if(curr -> left){
                    nodeQueue.push(curr -> left);
                }
                if(curr -> right){
                    nodeQueue.push(curr -> right);
                }
            }
            if(!flag){
                reverse(levelNodes.begin(), levelNodes.end());
                flag = true;
            }
            else{
                flag = false;
            }
            answer.push_back(levelNodes);
        }
        return answer;
    }
};