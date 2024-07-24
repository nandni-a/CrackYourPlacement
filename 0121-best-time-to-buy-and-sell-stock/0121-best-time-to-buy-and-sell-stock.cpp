class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0){
            return -1;
        }
        int min_stock=INT_MAX;
        int profit=0;
        for (int price : prices) {
            if (price < min_stock) {
                min_stock = price; // Update min_stock if current price is lower
            } else {
                profit = max(profit, price - min_stock); // Calculate potential profit
            }
        }
        return profit;
        
        
    }
};