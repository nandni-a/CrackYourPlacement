// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
        vector<int> ans;
        Node* curr= node;
        while(curr!= nullptr){
            if(curr->right== nullptr){
                ans.push_back(curr->data);
                curr= curr->left;
            }
            else{
                Node* temp= curr-> right;
                while(temp->left!= nullptr and temp->left!= curr){
                    temp= temp->left;
                    
                }
                if(temp->left== curr){
                    temp->left= nullptr;
                    curr= curr->left;
                    
                }
                else{
                   ans.push_back(curr->data);
                   temp->left= curr;
                   curr= curr->right;
                   
                }
            }
        }
        reverse(ans.begin(), ans.end());
        // return ans;
    return ans;
    }
};