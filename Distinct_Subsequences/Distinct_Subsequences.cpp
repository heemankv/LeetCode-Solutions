// TABULATION
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<double>> dp(n+1,vector<double>(m+1,-1));

        // base cases
        for(int i = 0 ; i <= n; i ++){
            dp[i][0] = 1; // when j < 0 vala case hai shifted, so 1 stirng is made
        }
        // why j from 1 ? -> bhai [0][0] uper bol diya hai ki haan bhai bilkul ban gya hai coz i < 0 and j < 0, but neeche mene ushi cheez ko rewrite krdiya into a 0 hence we'll skip the case for j = 0 in below
        for(int j = 1 ; j <= m; j ++){
            dp[0][j] = 0; // when i < 0 vala case hai shifted, so 0 stirng is made
        }

        // now the answer overflows so we need double

        for(int Si = 1 ; Si <= n ; Si++){
            for(int Ti = 1; Ti <= m ; Ti++){
                double answer = 0;
                // recursive approach
                if(s[Si-1] == t[Ti-1]){
                    // Are they equal, have I found an answer ?
                    // I am picking what I have found
                    double pick = dp[Si-1][Ti-1];
                    // I am not picking what I have found
                    double notPick = dp[Si-1][Ti];
                    answer = pick + notPick;
                }else{
                    // I have not found an answer !
                    double notPick = dp[Si-1][Ti];
                    answer = notPick;
                }
                //return statement
                dp[Si][Ti] = answer;
            }
        }
        return (int) dp[n][m];    
    }
};



// class Solution {
// private:
//     int calculation(int Si, int Ti, const string &s, const string &t, vector<vector<int>> &dp){
//         // base case
//         if(Ti < 0){
//             return 1;
//         }
//         // the order of writing the base cases allows for writing less cases 
//         // here the second base case will run only when the first is not satisfied, i.e j > 0
//         if(Si < 0){
//             return 0;
//         }

//         // dp check 
//         if(dp[Si][Ti] != -1){
//             return dp[Si][Ti];
//         }

//         int answer = 0;
//         // recursive approach
//         if(s[Si] == t[Ti]){
//             // Are they equal, have I found an answer ?
//             // I am picking what I have found
//             int pick = calculation(Si-1, Ti-1, s,t, dp);
//             // I am not picking what I have found
//             int notPick = calculation(Si-1, Ti, s,t, dp);
//             answer = pick + notPick;
//         }else{
//             // I have not found an answer !
//             int notPick = calculation(Si-1, Ti, s,t, dp);
//             answer = notPick;
//         }
//         //return statement
//         return dp[Si][Ti] = answer;
//     }

// public:
//     int numDistinct(string s, string t) {
//         int n = s.length();
//         int m = t.length();

//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         calculation(n-1, m-1, s, t, dp);
//         return dp[n-1][m-1];    
//     }
// };
