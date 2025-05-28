/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class Val {
public:
    int maxi, mini, size;
    Val(int minii, int maxi, int size) {
        this->maxi = maxi;
        this->mini = minii;
        this->size = size;
    }
};


class Solution {
  public:
    Val solve(Node* root) {
        if (!root) {
            return Val(INT_MAX, INT_MIN, 0);
        }

        auto left = solve(root->left);
        auto right = solve(root->right);

        if (left.maxi < root->data && root->data < right.mini) {
            return Val(min(root->data, left.mini),
                       max(root->data, right.maxi),
                       left.size + right.size + 1);
        }

        return Val(INT_MIN, INT_MAX, max(left.size, right.size));
    }
   
    int largestBst(Node *root) {
        // Your code here
        return solve(root).size;
        
    }
};