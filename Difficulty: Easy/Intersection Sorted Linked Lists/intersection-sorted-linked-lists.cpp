/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

class Solution {
  public:
    Node* findIntersection(Node* head1, Node* head2) {
        // code goes here.
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        Node* list1=head1;
        Node* list2=head2;
        
        while(list1!=NULL && list2!=NULL){
            if(list1->data == list2->data){
                Node* newNode=new Node(list1->data);
                temp->next=newNode;
                temp=temp->next;
                if(list1)
                    list1=list1->next;
                if(list2)
                    list2=list2->next;
            }
            else if(list1->data < list2->data){
                if(list1)
                    list1=list1->next;
            }
            else{
                if(list2)
                    list2=list2->next;
            }
        }
        return dummy->next;
    }
};