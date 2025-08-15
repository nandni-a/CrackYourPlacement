class Solution {
public:
    Node* reverseList(Node* list) {
        if (list == NULL || list->next == NULL) {
            return list;
        }
        Node* prev = NULL;
        Node* temp = list;
        while (temp != NULL) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }

    Node* addTwoLists(Node* head1, Node* head2) {
        Node* list1 = reverseList(head1);
        Node* list2 = reverseList(head2);
        
        int carry = 0;
        Node* dummy = new Node(-1);
        Node* temp = dummy;
        
        while (list1 != NULL || list2 != NULL) {
            int a = 0;
            if (list1 != NULL) {
                a = list1->data;
            }
            
            int b = 0;
            if (list2 != NULL) {
                b = list2->data;
            }
            
            int sum = a + b + carry;
            carry = sum / 10;
            Node* newNode = new Node(sum % 10);
            
            temp->next = newNode;
            temp = temp->next;
            
            if (list1 != NULL) {
                list1 = list1->next;
            }
            if (list2 != NULL) {
                list2 = list2->next;
            }
        }
        
        if (carry != 0) {
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
        
         Node * nHead = reverseList(dummy->next);
            
        while(nHead !=  NULL && nHead->data == 0) nHead = nHead->next;
        
        return nHead;
    }
};