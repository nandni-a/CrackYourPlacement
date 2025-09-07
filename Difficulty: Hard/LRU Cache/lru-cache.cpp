class LRUCache {
  public:
    class Node{
        public:
        int key,val;
        Node* prev;
        Node* next;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            prev=next=NULL;
            
        }
        
    };
    Node* head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    unordered_map<int,Node*>mapp;
    int limit;
    LRUCache(int cap) {
        // code here
        limit=cap;
        head->next=tail;
        tail->prev=head;
        
    }
    void addNode(Node* newNode){
        Node* oldNext=head->next;
        head->next=newNode;
        newNode->next=oldNext;
        newNode->prev=head;
        oldNext->prev=newNode;
    }
    void delNode(Node* oldNode){
        Node* oldPrev=oldNode->prev;
        Node* oldNext=oldNode->next;
        oldPrev->next=oldNext;
        oldNext->prev=oldPrev;

    }
    int get(int key) {

        // code here
        if(mapp.find(key)==mapp.end()) return -1;
        Node* ansNode=mapp[key];
        int ans=ansNode->val;
        
        delNode(ansNode);
        addNode(ansNode);
        return ans;
        
    }

        
    void put(int key, int value) {
        // code here
        if(mapp.find(key)!=mapp.end()){
            Node* oldNode=mapp[key];
            mapp.erase(key);
            delNode(oldNode);
        }
        if(mapp.size()==limit){
            mapp.erase(tail->prev->key);
            delNode(tail->prev);
        }
        Node* newNode=new Node(key,value);
        addNode(newNode);
        mapp[key]=newNode;
    }
};