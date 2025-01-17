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
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Q. Preorder inorder postorder in a single traversal
    // Write your code here.
    vector<vector<int>> answer;
    if(!root){
        return answer;
    }
    vector<int> preOrder, inOrder, postOrder;
    stack<pair<TreeNode *, int>> nodeVisitStack;
    nodeVisitStack.push({root, 1});
    while(!nodeVisitStack.empty()){
        auto iterator = nodeVisitStack.top();
        nodeVisitStack.pop();
        TreeNode* currNode = iterator.first;
        int visitCount = iterator.second;
        if(visitCount == 1){
            preOrder.emplace_back(currNode -> data);
            visitCount += 1;
            nodeVisitStack.push({currNode, visitCount});
            if(currNode -> left){
                nodeVisitStack.push({currNode -> left, 1});
            }
        }
        else if(visitCount == 2){
            inOrder.emplace_back(currNode -> data);
            visitCount += 1;
            nodeVisitStack.push({currNode, visitCount});
            if(currNode -> right){
                nodeVisitStack.push({currNode -> right, 1});
            }
        }
        else{
            postOrder.emplace_back(currNode -> data);
        }
    }
    answer.emplace_back(inOrder);
    answer.emplace_back(preOrder);
    answer.emplace_back(postOrder);
    return answer;
}