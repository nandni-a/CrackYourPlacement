// User Fuction template for C++
/*
// Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int ans;
    int dfs(Node* root){
        if(!root) return 0;
        int l=max(0,dfs(root->left));
        int r=max(0,dfs(root->right));
        ans=max(ans,(l+r+root->data));
        return root->data + max(l,r);
    }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
         ans=INT_MIN;
        dfs(root);
        return ans;
    }
};