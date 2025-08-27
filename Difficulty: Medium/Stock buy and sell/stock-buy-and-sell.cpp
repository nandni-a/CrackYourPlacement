class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
     int profit=0;
     for(int i=1;i<arr.size();i++){
         int n=arr[i]-arr[i-1];
         profit=max(profit,profit+n);
     }
     return profit;
    }
};