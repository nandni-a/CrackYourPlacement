/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node* nextRight;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        nextRight = nullptr;
    }
};

*/

class Solution {
  public:

    Node* connect(Node* root) {
        if(!root) return NULL;
        // code here
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            Node* prev=NULL;
            while(size--){
                Node* top=q.front();
                q.pop();
                top->nextRight=prev;
                prev=top;
                if(top->right){
                    q.push(top->right);
                }
                
                if(top->left){
                    q.push(top->left);
                }
            }
        }
        return root;
        
    }
};