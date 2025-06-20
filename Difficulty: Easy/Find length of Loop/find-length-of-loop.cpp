/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int find(Node* slow, Node* fast){
        int cnt=1;
        fast=fast->next;
        while(slow!=fast){
            cnt++;
            fast=fast->next;
        }
        return cnt;
    }
    int countNodesinLoop(Node *head) {
        // Code here
        Node * slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next != NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return find(slow,fast);
            }
        }
        return 0;
    }
};