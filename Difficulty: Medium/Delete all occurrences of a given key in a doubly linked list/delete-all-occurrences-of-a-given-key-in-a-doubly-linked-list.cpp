// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        // Write your code here
        Node* temp = *head_ref;

    while (temp != NULL) {
        if (temp->data == x) {
            Node* toDelete = temp;
            Node* nextNode = temp->next;

            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                
                *head_ref = temp->next;
            }

            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }

            delete toDelete;
            temp = nextNode;
        } else {
            temp = temp->next;
        }
    }
        
    }
};