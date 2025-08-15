/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* getMid(Node* head){
        if (!head) return head;
        Node* slow=head;
        Node* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
        
    }
    Node* merge(Node* left,Node* right){
        if (!left) return right;
        if (!right) return left;
        Node* res=NULL;
        if(left->data <= right->data){
            res=left;
            res->next=merge(left->next,right);
        }
        else{
            res=right;
            res->next=merge(left,right->next);
        }
        return res;
    }
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(!head || !head->next){
            return head;
        }
        Node* mid=getMid(head);
        Node* nextToMid=mid->next;
        mid->next=NULL;
        Node* left=mergeSort(head);
        Node* right=mergeSort(nextToMid);
        return merge(left,right);
    }
};