/*
class Node {
  public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};
*/
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
        Node* neww=new Node(x);
        Node* temp=head;
        if(head==NULL){
            return neww;
        }
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=neww;
        return head;
    }
};