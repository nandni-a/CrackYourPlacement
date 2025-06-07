/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(head==NULL){
            return NULL;
        }
        Node*temp=head;
        int cnt=1;
        while(cnt!=x && temp!=nullptr)
        {
            temp=temp->next;
            cnt++;
        }
        
        if(temp==NULL){
            return head;
        }
        if(cnt==1){
            if(head->next){
                head=head->next;
                head->prev=NULL;
                delete temp;
                return head;
            }
        }
        temp->prev->next=temp->next;
        if(temp->next)
        temp->next->prev=temp->prev;
    
        delete(temp);
        
        return head;
    }
};