class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,1e9));
        
        // base case
        for(int t = 0 ; t <= amount ;t++){
            // if divisible
            if(t%coins[0] == 0){
                dp[0][t] =  t/coins[0];
            } 
        }

        for(int ind=1; ind<coins.size(); ind++){
            for(int t=0; t<=amount; t++){
                // take 
                int take = 1e9;
                if(t >= coins[ind]){
                    // can be used
                    take = 1 + dp[ind][t-coins[ind]];
                }
                // not take 
                int notTake = 1e9;
                notTake = 0 + dp[ind-1][t];

                // my value
                dp[ind][t] = min(take,notTake);
            }
        }
        // what if it's impossible
        // the value would be greater than equal to 1e9
        return dp[coins.size()-1][amount] >= 1e9 ? -1 : dp[coins.size()-1][amount];
    }
};
