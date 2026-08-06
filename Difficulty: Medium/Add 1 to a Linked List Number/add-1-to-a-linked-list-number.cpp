/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int helper(Node* temp){
        if(temp==NULL){
            return 1;
        }
        int carry=helper(temp->next);
        temp->data = temp->data +carry ;
        if(temp->data < 10){
            return 0;
        }
        temp->data = 0;
        return 1;
    }
    Node* addOne(Node* head) {
        // code here
        Node* temp=head;
        int carry=helper(temp);
        if(carry==1){
            Node* newNode= new Node(1);
            newNode->next=head;
            return newNode;
        }
        return head;
        
    }
};