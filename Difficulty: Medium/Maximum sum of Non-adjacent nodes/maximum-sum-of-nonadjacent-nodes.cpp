/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*,int>dp;
    int getMaxSum(Node *root) {
        // code here
        if(!root) return 0;
        if(dp.find(root) !=dp.end()){
            return dp[root];
        }
        int include=root->data;
        
        if(root->left){
            include+= getMaxSum(root->left->left);
            include+= getMaxSum(root->left->right);
        }
        if(root->right){
            include+= getMaxSum(root->right->left);
            include+= getMaxSum(root->right->right);
        }
        int exclude= getMaxSum(root->left) + getMaxSum(root->right);
        return dp[root]= max(include,exclude);
        
    }
};