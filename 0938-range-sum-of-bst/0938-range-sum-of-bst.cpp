/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum(TreeNode* root, int low, int high,int &ans){
        if(root==NULL){
            return 0;
        }
        if(root->val <= high && root->val >= low){
            ans+=root->val;
        }
        
        sum(root->left,low,high,ans);
        sum(root->right,low,high,ans);
        
        return ans;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans=0;
        return sum(root,low,high,ans);
    }
};