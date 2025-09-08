/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int getCount(Node *root, int l, int h) {
        // your code here
        if(root==NULL) return 0;
        if(root->data >=l && root->data <=h){
            return 1+ getCount(root->left,l,h) + getCount(root->right,l,h);
        }
        else if(root->data >h){
            return getCount(root->left,l,h);
        }
        return getCount(root->right,l,h);
    }
};