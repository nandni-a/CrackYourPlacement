//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
// class Solution{
//   public:
//     bool solve(Node *root,int mini,int maxi){
//         if(root==NULL){
//             return false;
//         }
//         if(!root->right && !root->left){
//             if (root->data == 1 && mini == 1) { 
//                 return true; 
//             }
//             return (root->data >= mini && root->data <= maxi);
//         }
//         return (root->left,mini,root->data-1) && (root->right,root->data+1,maxi);
//     }
//     bool isDeadEnd(Node *root)
//     {
//         return solve(root,1,INT_MAX);
//         //Your code here
//     }
// };

class Solution{
  public:
    bool helper(Node* root,set<int>st)
    {
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL)
        {
            if(st.find(root->data-1)!=st.end() && st.find(root->data+1)!=st.end()) 
                return true;
        }
        st.insert(root->data);
      return helper(root->left,st) || helper(root->right,st);
    
    }
    bool isDeadEnd(Node *root)
    {
        set<int>st;
        st.insert(0);
        return helper(root,st);
        
    }
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    
cout << "~" << "\n";
}
}


// } Driver Code Ends