/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
        Node* temp=head;
        while(temp!=NULL && temp->next!=NULL ){
            if (temp->data == temp->next->data) {
            Node* dup = temp->next;

            
            temp->next = dup->next;

            
            if (dup->next != NULL) {
                dup->next->prev = temp;
            }

            delete dup;  
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
    
};