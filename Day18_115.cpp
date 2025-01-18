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
    int widthOfBinaryTree(TreeNode* root) {
        // Q. Maximum Width of Binary Tree
        if(!root){
            return 0;
        }

        long long maxWidth = 0;
        queue<pair<TreeNode *, long long>> bfsQueue;
        bfsQueue.push({root, 0});
        while(!bfsQueue.empty()){
            long long size = bfsQueue.size();
            long long levelFront = bfsQueue.front().second;

            long long firstPosition, lastPosition;
            for(int levelNode = 0; levelNode < size; ++levelNode){
                long long relativePosition = bfsQueue.front().second - levelFront;
                TreeNode *currNode = bfsQueue.front().first;
                bfsQueue.pop();
                if(levelNode == 0){
                    firstPosition = relativePosition;
                }
                if(levelNode == size - 1){
                    lastPosition = relativePosition;
                }
                if(currNode -> left){
                    bfsQueue.push({currNode -> left, relativePosition * 2 + 1});
                }
                if(currNode -> right){
                    bfsQueue.push({currNode -> right, relativePosition * 2 + 2});
                }
            }
            maxWidth = max(maxWidth, lastPosition - firstPosition + 1);
        }
        return maxWidth;
    }
};