/*
Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left, *right;
};
*/
// your task is to complete this function
class Solution {
  public:
    int ans=-1;
    int solve(Node* root,int k,int node){
        if(root==NULL){
            return -1;
        }
        if(root->data==node){
            return 1;
        }
        int left=solve(root->left,k,node);
        int right=solve(root->right,k,node);
        if(left==-1 && right==-1){
            return -1;
        }
        int valid= ( left==-1)? right:left;
        if(valid==k && ans==-1){
            ans=root->data;
        }
        return valid+1;
    }
    int kthAncestor(Node *root, int k, int node) {
        // Code here
        
        solve(root,k,node);
        return ans;
    }
};
