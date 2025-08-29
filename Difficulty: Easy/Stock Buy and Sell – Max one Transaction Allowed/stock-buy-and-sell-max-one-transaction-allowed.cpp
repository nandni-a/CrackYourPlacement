class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int mini=prices[0];
        int profit=0;
        int maxProfit=0;
        for(int it:prices){
            mini=min(it,mini);
            profit=it-mini;
            maxProfit=max(maxProfit,profit);
        }
        return maxProfit;
    }
};
