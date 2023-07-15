#include <bits/stdc++.h>

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int totalRows = grid.size();
        int totalCols = grid[0].size();

        vector<vector<int>> dp(totalRows, vector<int>(totalCols,0));
        for(int row = totalRows -1 ; row>=0; row--){
            for(int col = totalCols-1 ; col >= 0; col--){
                
                if(row == totalRows-1 && col == totalCols-1){
                    dp[row][col] = grid[row][col];
                }
                else{
                int ansD = 1e9;
                int ansR = 1e9;

                if(row+1 < totalRows){
                    // down valid call
                    ansD = dp[row+1][col];
                }
                if(col+1 < totalCols){
                    // right valid call
                    ansR = dp[row][col+1];
                }

                dp[row][col] = grid[row][col] + min(ansD, ansR);
                }
            }
        }
        return dp[0][0] >= 1e9? 0:dp[0][0];          
    }
};
