// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/
static bool cmp(pair<int,int>&a , pair<int,int>& b){
    double r1=(double) a.first/a.second;
    double r2=(double) b.first/b.second;
    return r1>r2;
}
class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        vector<pair<int,int>>arr;
        for(int i=0;i<val.size();i++){
            arr.push_back({val[i],wt[i]});
        }
        sort(arr.begin(),arr.end(),cmp);
        double ans=0;
        for(int i=0;i<arr.size();i++){
            if(capacity >= arr[i].second){
                ans+= arr[i].first;
                capacity -= arr[i].second;
            }
            else{
                ans += ((double) arr[i].first/(double) arr[i].second) * capacity;
                break;
            }
            if(capacity==0) return ans;
        }
        return ans;
        
        
    }
};
