class Solution {
private: 
    // Recursive Code
    int climbwaysRecursive(int n){
        if(n == 1){
            return 1;
        }else if(n == 2){
            return 2;
        }
        //  call my subordinates
        int one = climbwaysRecursive(n-1);
        int two = climbwaysRecursive(n-2);
        return one + two;
    }


private: 
    // Memoization Code
    int climbwaysMemo(int n, vector<int> & dp){
        if(dp[n] != 0 || n < 2){
            return dp[n];
        }
        //  call my subordinates
        int one = climbwaysMemo(n-1,dp);
        int two = climbwaysMemo(n-2,dp);
        return dp[n] = one + two;
    }



public:
    int climbStairs(int n) {
        // Recursive Start
        // return climbwaysRecursive(n);
        // Recursive END

        // Memoization Start
        // vector<int> dp(n+1,0);
        // dp[0] = 1;
        // dp[1] = 1;
        // if(n  >= 2){
        //     climbwaysMemo(n, dp);
        // }
        // return dp[n];
        // Memoization End 

        // Tabulation Start
        // vector<int> dp(n+1,0);
        // // base case
        // dp[0] = 1;
        // dp[1] = 1;
        // // calculate from 2. 0,1 done already.
        // for(int i = 2; i < n+1 ; i++){
        //     dp[i] = dp[i-1] + dp[i-2];
        // }
        // return dp[n];
        // Tabulation End

        // Space Optimization Start
        // base case
        int m1 = 1;
        int m2 = 1;
        // calculate from 2. 0,1 done already.
        for(int i = 2; i < n+1 ; i++){

            int xD = m1 + m2;
            m2 = m1;
            m1 = xD;
        }
        return m1;
        // Space Optimization Start

    }
};
