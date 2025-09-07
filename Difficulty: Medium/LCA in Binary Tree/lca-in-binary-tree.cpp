/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node() {
        data = 0;
        left = right = NULL;
    }

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
  public:
    Node* lowest(Node* root,int n1,int n2){
        if(root==NULL){
            return NULL;
        }
        if(root->data == n1 || root->data ==n2){
            return root;
        }
        Node* left=lowest(root->left,n1,n2);
        Node* right=lowest(root->right,n1,n2);
        if(left!=NULL && right!=NULL){
            return root;
        }
        else if(left!=NULL){
            return left;
        }
        else{
            return right;
        }
    }
    Node* lca(Node* root, int n1, int n2) {
        //  code here
        return lowest(root,n1,n2);
        
    }
};