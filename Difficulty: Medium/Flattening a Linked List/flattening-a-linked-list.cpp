/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* mergeTwoLists(Node* list1, Node* list2) {
        Node* t1=list1;
        Node* t2 =list2;
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        while(t1!=NULL && t2!=NULL){
            if(t1->data <= t2->data){
                temp->bottom=t1;
                temp=t1;
                t1=t1->bottom;

            }
            else{
                temp->bottom=t2;
                temp=t2;
                t2=t2->bottom;
            }
            temp->next=NULL;
        }
        if(t1!=NULL){
            temp->bottom=t1;
        }
        else{
            temp->bottom=t2;
        }
        return dummy->bottom;
    }
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL || root->next==NULL){
            return root;
        }
        Node* merged=flatten(root->next);
        return mergeTwoLists(root,merged);
        
        
    }
};