/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* head) {
        // code here
        if(head==NULL){
            return NULL;
        }
        Node* temp=head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->data == temp->next->data){
                Node* dup=temp->next;
                
                temp->next=dup->next;
                if(dup->next!=NULL) dup->next->prev= temp;
                delete dup;
            }
            else{
                temp=temp->next;
            }
        }
        return head;
    }
};