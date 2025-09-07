/*Complete the function below

struct Node {
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
    int curr=-1;
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        if(root==NULL) return -1;
        int left=kthSmallest(root->left,k);
        if(left!=-1){
            return left;
        }
        curr= curr==-1 ? 1:curr+1;
        if(curr==k){
            return root->data;
        }
        return kthSmallest(root->right,k);
        
    }
};