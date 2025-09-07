class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        //  code here
        int total_gas=0;
        int total_cost=0;
        int n=gas.size();
        for(int i=0;i<n;i++){
            total_gas+=gas[i];
            total_cost+=cost[i];
        }
        if(total_gas<total_cost) return -1;
        int total=0,ans=0;
        for(int i=0;i<n;i++){
            total+=(gas[i]-cost[i]);
            if(total<0){
                ans=(i+1)%n;
                total=0;
            }
        }
        return ans;
    }
};