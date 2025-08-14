/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
        Node* curr=head;
        unordered_map<Node*,int>vis;
        while(curr!=NULL && curr->next!=NULL){
            if(vis[curr->next]){
                curr->next=NULL;
                break;
            }
            vis[curr]=1;
            curr=curr->next;
        }
    }
};