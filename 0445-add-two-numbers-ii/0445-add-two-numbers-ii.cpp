/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode*head){
        ListNode*p,*q;
        p=head;
        q=NULL;
        while(p!=NULL){
            ListNode* on=p->next;
            p->next=q;
            q=p;
            p=on;
            
        }
        return q;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head1=reverse(l1);
        ListNode* head2=reverse(l2);
        
        ListNode*dummy=new ListNode();
        ListNode*temp=dummy;
        int carry=0;
        while(head1!=NULL || head2!=NULL || carry){
            int sum=0;
            if(head1!=NULL){
                sum+=head1->val;
                head1=head1->next;
            }
            if(head2!=NULL){
                sum+=head2->val;
                head2=head2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        dummy=dummy->next;
        dummy=reverse(dummy);
        return dummy;
        
    }
};