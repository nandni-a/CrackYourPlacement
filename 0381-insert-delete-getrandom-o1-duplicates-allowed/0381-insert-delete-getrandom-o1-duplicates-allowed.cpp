class RandomizedCollection {
public:
    unordered_map<int,int> map;
    vector<int> v;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        if(map[val]==0){
            v.push_back(val);
            map[val]++;
            return true;
            
            
        }
        else if(map[val] >0 ){
            v.push_back(val);
            map[val]++;
            return false;
            
        }
        return false;
        
        
    }
    
    bool remove(int val) {
        if(map[val] > 0){
            auto it = find(v.begin(),v.end(),val);
            v.erase(it);
            map[val]--;
            return true;
        }
        
        return false;
        
        
    }
    
    int getRandom() {
        return v[rand()%v.size()];
        
        
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */