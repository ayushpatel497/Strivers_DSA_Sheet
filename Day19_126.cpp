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
    TreeNode* build(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd,  unordered_map<int, int>& nodeIndexMap){
        if(postStart > postEnd || inStart > inEnd){
            return NULL;
        }

        TreeNode *root = new TreeNode(postorder[postEnd]);
        int inRoot = nodeIndexMap[root -> val];
        int numsRight = inEnd - inRoot;

        root -> left = build(inorder, inStart, inRoot - 1, postorder, postStart, postEnd - numsRight - 1, nodeIndexMap);
        root -> right = build(inorder, inRoot + 1, inEnd, postorder, postEnd - numsRight, postEnd - 1, nodeIndexMap);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Q. Construct Binary Tree from Inorder and Postorder Traversal
        unordered_map<int, int> nodeIndexMap;
        for(int node = 0; node < inorder.size(); ++node){
            nodeIndexMap[inorder[node]] = node;
        }

        return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, nodeIndexMap);
    }
};