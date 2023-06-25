class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int curr   = 0;
        int index  = 0;
        while(index<n){
            if(prices[curr] < prices[index]){
                profit = max(profit,prices[index] - prices[curr]);
            }
            else{
                curr = index;
            }
            index++;
        }
        return profit;
    }
};
