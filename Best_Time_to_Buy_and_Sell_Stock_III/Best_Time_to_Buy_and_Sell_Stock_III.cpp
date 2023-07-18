class Solution {
public:
    int func(int i,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(cap==0 || i==prices.size()){
            return 0;
        }
        if(dp[i][buy][cap]!=-1){
            return dp[i][buy][cap];
        }

        if(buy){
            return dp[i][buy][cap]=max((-1)*prices[i]+func(i+1,0,cap,prices,dp),func(i+1,1,cap,prices,dp));
        }else{
            return dp[i][buy][cap]=max(prices[i]+func(i+1,1,cap-1,prices,dp),func(i+1,0,cap,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
        return func(0,1,2,prices,dp);
        
    }
};
