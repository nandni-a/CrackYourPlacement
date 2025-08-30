// User function Template for C++

/* Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/

class Solution {
  public:
    int ans;
    bool solve(Node* root){
        if(root==NULL) return true;
        bool left=solve(root->left);
        bool right=solve(root->right);
        if(left && right){
            if(root->left!=NULL && root->left->data != root->data) return false;
            if(root->right!=NULL && root->right->data != root->data) return false;
            ans++;
            return true;
        }
        return false;
    }
    int singlevalued(Node *root) {
        // code here
         ans=0;
         solve(root);
         return ans;
        
    }
};
