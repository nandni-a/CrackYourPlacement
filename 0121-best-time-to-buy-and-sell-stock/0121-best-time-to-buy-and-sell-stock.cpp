class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return -1;
        }
        int min_stock=INT_MAX;
        int profit=0;
        for(int i=0;i<prices.size();i++){
            int diff=prices[i]-min_stock;
            profit=max(profit,diff);
            min_stock=min(min_stock,prices[i]);
            
        }
        return profit;
        
        
    }
};