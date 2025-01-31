//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x)
        : data(x)
        , next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;
        head = head->next;
    }
    cout << '\n';
}


// } Driver Code Ends
// User function Template for C++

// class Solution {
//   public:
//     int getLength(Node* head) {
//         int len = 0;
//         while (head) {
//             len++;
//             head = head->next;
//         }
//         return len;
//     }
//     Node* padZeros(Node* head, int count) {
//         Node* temp = new Node(0);
//         temp->next = head;
//         head = temp;
//         while (count--) {
//             temp = new Node(0);
//             temp->next = head;
//             head = temp;
//         }
//         return head;
//     }
//     bool compareLists(Node* l1, Node* l2) {
//         while (l1 && l2) {
//             if (l1->data != l2->data) {
//                 return l1->data > l2->data; // Return true if l1 is greater
//             }
//             l1 = l1->next;
//             l2 = l2->next;
//         }
//         return false; // If lengths are equal, return false (assume l1 is greater)
//     }

//     Node* subLinkedList(Node* l1, Node* l2) {
//         int len1 = getLength(l1);
//         int len2 = getLength(l2);
    
//         // Pad zeros to the beginning of the shorter list
//         if (len1 < len2) {
//             l1 = padZeros(l1, len2 - len1);
//         } else if (len1 > len2) {
//             l2 = padZeros(l2, len1 - len2);
//         }
    
//         // Determine the larger list
//         Node* larger = compareLists(l1, l2) ? l1 : l2;
//         Node* smaller = compareLists(l1, l2) ? l2 : l1;
    
//         // Subtract the digits
//         Node* dummy = new Node(0);
//         Node* curr = dummy;
//         bool borrow = false;
    
//         while (larger) {
//             int diff = larger->data - smaller->data - borrow;
//             if (diff < 0) {
//                 diff += 10;
//                 borrow = true;
//             } else {
//                 borrow = false;
//             }
//             curr->next = new Node(diff);
//             curr = curr->next;
//             larger = larger->next;
//             smaller = smaller->next;
//         }
 
//         curr = dummy->next;
//         while (curr && curr->data == 0) {
//             Node* temp = curr;
//             curr = curr->next;
//             delete temp;
//         }
    
//         return curr;
        
//         // Your implementation of subLinkedList goes here
//         // Make sure to return the head of the resulting linked list
//     }
// };

class Solution {
  public:
  
    int findLength (Node*first){
        int count = 0;
        while(first){
            count ++;
            first = first->next;
        }
        return count;
    }
    
    Node*reverse(Node*first){
        Node*temp = first;
        Node*prev = NULL;
        while(temp){
            temp = temp->next;
            first->next = prev ;
            prev = first;
            first = temp;
        }
        return prev;
    }
    
    Node*removeLeadingZero (Node*first){
        while(first && first->data == 0){
            first = first->next;
        }
        if(first == NULL){
            return new Node(0);
        }
        return first;
    }
    
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        head1 = removeLeadingZero(head1);
        head2 = removeLeadingZero(head2);
        
        Node*temp1 = head1;
        Node*temp2 = head2;
        
        int len1 = findLength(head1);
        int len2 = findLength(head2);
        
        Node*greater = head1;
        Node*small = head2;
        
        if(len1 > len2){
            greater = head1;
            small = head2;
        }
        else if(len1 < len2){
            greater = head2;
            small = head1;
        }
        else{
            while(head1 && head2){
                if(head1->data > head2->data){
                    greater = temp1;
                    small = temp2;
                    break;
                }
                else if(head1->data < head2->data){
                    greater = temp2;
                    small = temp1;
                    break;
                }
                else{
                    head1 = head1->next;
                    head2 = head2->next;
                }
            }
        }
        
        greater = reverse(greater);
        small = reverse(small);
        
        Node*ans = new Node(-1);
        Node*ansHead = ans;
        
        int borrow = 0;
        while(greater && small){
            if((greater->data + borrow) < small->data){
                int val = greater->data + 10 - small->data + borrow;
                borrow = -1;
                Node*newNode = new Node(val);
                ans->next = newNode;
                ans = newNode;
                
            }
            else{
                int val = greater->data + borrow - small->data;
                borrow = 0;
                Node*newNode = new Node(val);
                ans->next = newNode;
                ans = newNode;
            }
            
            greater = greater->next;
            small = small->next;
        }
        
        while(greater){
            if((greater->data + borrow) < 0 ){
                int val = greater->data + 10  + borrow;
                borrow = -1;
                Node*newNode = new Node(val);
                ans->next = newNode;
                ans = newNode;
            }
            else{
                int val = greater->data + borrow ;
                borrow = 0;
                Node*newNode = new Node(val);
                ans->next = newNode;
                ans = newNode;
            }
            greater = greater->next;
            
        }
        ansHead = reverse(ansHead->next);
        return removeLeadingZero(ansHead);
    }
};

//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        cin >> input1 >> input2;
        for (char ch : input1) {
            int tmp = ch - '0';
            Node* new_node = new Node(tmp);
            if (!head1) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        for (char ch : input2) {
            int tmp = ch - '0';
            Node* new_node = new Node(tmp);
            if (!head2) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node* result = obj.subLinkedList(head1, head2);
        printList(result);
    }
    return 0;
}

// } Driver Code Ends