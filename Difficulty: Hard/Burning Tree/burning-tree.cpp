/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* parentMapping(Node* root, int target,map<Node*,Node*>&nodeToParent){
        Node*res=NULL;
        queue<Node*>q;
        q.push(root);
        nodeToParent[root]=NULL;
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            if(front->data==target){
                res=front;
            }
            if(front->left){
                nodeToParent[front->left]=front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right]=front;
                q.push(front->right);
            }
        }
        return res;
    }
    void burnTree(Node* root,map<Node*,Node*>&nodeToParent,int &ans){
        map<Node*,bool>vis;
        queue<Node*>q;
        q.push(root);
        vis[root]=true;
        
        while(!q.empty()){
            int size=q.size();
            bool flag=0;
            for(int i=0;i<size;i++){
                Node*front=q.front();
                q.pop();
                
                if(front->left && !vis[front->left] ){
                    q.push(front->left);
                    flag=1;
                    vis[front->left]=true;
                }
                if(front->right && !vis[front->right] ){
                    q.push(front->right);
                    flag=1;
                    vis[front->right]=true;
                }
                if(nodeToParent[front] && !vis[nodeToParent[front]]){
                    q.push(nodeToParent[front]);
                    flag=1;
                    vis[nodeToParent[front]]=true;
                }
            }
            if(flag==1) ans++;
        }
        
    }
    int minTime(Node* root, int target) {
        // code here
        int ans=0;
        map<Node*,Node*>nodeToParent;
        Node* targetNode=parentMapping(root,target,nodeToParent);
        burnTree(targetNode,nodeToParent,ans);
        return ans;
    }
};