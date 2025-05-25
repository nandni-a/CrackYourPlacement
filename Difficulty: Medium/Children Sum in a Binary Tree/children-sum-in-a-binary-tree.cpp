/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool solve(Node*root){
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        int leftSum,rightSum;
        if(root->left){
            leftSum=root->left->data;
        }
        else{
            leftSum=0;
        }
        if(root->right){
            rightSum=root->right->data;
        }
        else{
            rightSum=0;
        }
        if(root->data != leftSum+rightSum) return false;
        return solve(root->left) && solve(root->right);
    }
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // Add your code here
        return solve(root);
    }
};