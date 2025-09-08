/*The structure of the Binary Tree Node  is
struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};*/

class Solution {
  public:
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    string solve(Node* root,bool &found,unordered_map<string,int>&mapp){
        if(!root){
            return "$";
        }
        string left=solve(root->left,found,mapp);
        string right=solve(root->right,found,mapp);
        string s= to_string(root->data)+"," +left+","+right;
        if(left!="$" || right!="$"){
            mapp[s]++;
            if(mapp[s]==2){
                found= true;
            }
        }
        return s;
    }
    int dupSub(Node *root) {
        // code here
        bool found=false;
        unordered_map<string,int>mapp;
        solve(root,found,mapp);
        if(found) return 1;
        return 0;
    }
};