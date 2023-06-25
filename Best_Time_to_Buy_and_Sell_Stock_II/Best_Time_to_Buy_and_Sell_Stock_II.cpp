class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, len=prices.size();
        for(int i=1; i<len; i++)
        {
            profit+=max(prices[i]-prices[i-1],0);
        }
        return profit;
    }
    // int maxProfit(vector<int>& prices) {
    //     int n = prices.size();
    //     int totalProfit = 0;
    //     int index = 0;
    //     int boughtIndex = -1;
    //     int sellIndex = -1;

    //     // bought at 0th index

    //     while(index < n){
    //         // buy
    //         if(prices[index] >= prices[index+1]){
    //             if(boughtIndex !=-1){
    //                 sellIndex = index;
    //                 totalProfit+= prices[sellIndex] - prices[boughtIndex];
    //                 sellIndex = -1;
    //                 boughtIndex = -1;
    //             }
              
    //         }
    //         else if(prices[index]  < prices[index+1]){
    //             if(boughtIndex == -1){
    //                 boughtIndex = index;
    //             }
               
    //         }
    //         index++;
    //     }
    //     return totalProfit;
        
    // }
};
