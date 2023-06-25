class Solution {
public:

    bool fn (int indexAT, vector<int>& nums, vector<int> &dp ){
        if(indexAT >= nums.size()) return dp[indexAT] = false;

        if(indexAT == nums.size()-1){
            return dp[indexAT] =  true;
        }
        if(dp[indexAT] != -1){
            return dp[indexAT];
        }


        int x = false;
        for(int j = 0; j <= nums[indexAT]; j++){
                if(j == 0) continue;
                x = fn(indexAT+j, nums, dp);
                if(x) return  dp[indexAT] = true;
        }
        return dp[indexAT] = false;
    }



    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return fn(0,nums,dp);
    }
};
