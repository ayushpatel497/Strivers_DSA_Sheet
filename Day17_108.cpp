#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root){
    // Q. Binary Tree Morris Preorder Traversal
    // Write your code here.
    vector<int> ans;
    TreeNode *curr = root;
    TreeNode *prev;
    while(curr){
        if(!curr -> left){
            ans.emplace_back(curr -> data);
            curr = curr -> right;
        }
        else{
            prev = curr -> left;
            while(prev -> right && prev -> right != curr){
                prev = prev -> right;
            }
            if(!prev -> right){
                prev -> right = curr;
                ans.emplace_back(curr -> data);
                curr = curr -> left;
            }
            else{
                prev -> right = NULL;
                curr = curr -> right;
            }
        }
    }
    return ans;
}