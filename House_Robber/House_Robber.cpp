class Solution {

private: 
    int robingInProgress(vector<int>& nums, int index){
        // Base case : anything lesser than 0-index should return 0
        if(index < 0 ){
            return 0;
        }
        // call my subordinates
        // pick me
        int pick = nums[index] + robingInProgress(nums,index-2);
        // don't pick me
        int dontPick = robingInProgress(nums,index-1);

        return max(pick,dontPick);
    }



private: 
    int robingInProgressM(vector<int>& nums, int index, vector<int> &dp){
        // Base case : anything lesser than 0-index should return 0
        if(index < 0 ){
            return 0;
        }

        // dp check
        if(dp[index] != 0){
            return dp[index];
        }

        // call my subordinates
        // pick me
        int pick = nums[index] + robingInProgressM(nums,index-2, dp);
        // don't pick me
        int dontPick = robingInProgressM(nums,index-1, dp);

        return dp[index] = max(pick,dontPick);
    }

public:
    int rob(vector<int>& nums) {
        // Recursive Solution Start
        // return robingInProgress(nums,nums.size()-1);
        // Recursive Solution End

        // Memoization Solution Start
        // int n = nums.size();
        // vector<int> dp(n,0);
        // robingInProgressM(nums,n-1, dp);
        // return dp[n-1];
        // Memoization Solution End


        // Tabulation Start
        // 0 -> n-1
        // declare dp
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n+1,0);
        // base case
        dp[0] = 0;
        // the reason my code went to index = 1 is because it didn't pick index == 2,
        // and thus it needs to pick element index == 1;
        dp[1] = nums[0];

        for(int i = 1; i < n; i++){
            int val = nums[i];
            dp[i+1] = max(dp[i], dp[i-1] + val);

        }
        return dp[n];
        // Tabulation End

    }
};












