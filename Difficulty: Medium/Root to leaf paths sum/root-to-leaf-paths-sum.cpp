/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    int sum;
    void dfs(Node* root,int dig){
        if(root==NULL){
            return ;
        }
        int val=root->data;
        dig= (dig)*10 + val;
        if(root->left!=NULL && root->right !=NULL ){
            dfs(root->left,dig) ;
            dfs(root->right,dig);
        }
        else if(root->left !=NULL){
            dfs(root->left,dig) ;
        }
        else if(root->right!=NULL){
            dfs(root->right,dig);
        }
        else{
            sum+=dig;
            return;
        }
        return;
    }
    int treePathsSum(Node *root) {
        // code here.
        if(root==NULL) return 0;
        sum=0;
        dfs(root,0);
        return sum;
    }
};