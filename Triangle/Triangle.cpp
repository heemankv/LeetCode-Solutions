class Solution {
public:
    // Memoized Soln
    int memoizedSoln(vector<vector<int>>& triangle, int r, int c, int maxRows, int maxColumns, vector<vector<int>>& dp){
        
        // base case
        if(r == maxRows -1){
            return dp[r][c] = triangle[r][c];
        }

        // if already present
        if(dp[r][c] != -1){
            return dp[r][c];
        }

        // explore all paths
        int down =  triangle[r][c] +memoizedSoln(triangle, r+1, c, maxRows, maxColumns, dp);
        int right = triangle[r][c] + memoizedSoln(triangle, r+1, c+1, maxRows, maxColumns, dp);

        // return min of all paths, pushing to dp
        return dp[r][c] = min(down, right);
    } 


    // Recursive solution
    int recursiveSoln(vector<vector<int>>& triangle, int r, int c, int maxRows, int maxColumns){
        
        // base case
        if(r == maxRows -1){
            return triangle[r][c];
        }
        //  no edge case

        // explore all paths
        int down =  triangle[r][c] +recursiveSoln(triangle, r+1, c, maxRows, maxColumns);
        int right = triangle[r][c] + recursiveSoln(triangle, r+1, c+1, maxRows, maxColumns);

        // return min of all paths
        return  min(down, right);
    } 



    int minimumTotal(vector<vector<int>>& triangle) {
        int maxRows = triangle.size();
        int maxColumns = maxRows;

        // RECURSIVE (Top Down)
        // int answerr = recursiveSoln(triangle, 0, 0, maxRows, maxColumns);
        // return answerr;

        // Memoization Soln
        // Make dp
        // vector<vector<int>> dp (maxRows, vector<int> (maxColumns, -1));
        // memoizedSoln(triangle, 0, 0, maxRows, maxColumns, dp);
        // we called recursion on 0,0 so the same on dp will be returned
        // return dp[0][0];

        // Recursion top down hota hai
        // Recursion went from o,o to (n-1)(o->n-1)
        // So tabulation approach will be ulta

        //  define dp
        vector<vector<int>> dp (maxRows, vector<int> (maxColumns, 0));
        // now run for base case
        //  base calll -> all elements in the last row !
        for(int j = 0 ; j < maxColumns; j++){
            dp[maxRows-1][j] = triangle[maxRows-1][j];
        }
        // No edge case
        // for all the indexes available
        // run nested loops -> opposite to recursion , n-1 to 0
        // Obvservation : no need to run on last row
        for(int i = maxRows-2; i >=0; i--){
            for(int j = i; j >=0; j--){
                int down = triangle[i][j] +  dp[i+1][j];
                int downRight = triangle[i][j] +  dp[i+1][j+1];
                dp[i][j] = min(down,downRight);
            }
        }

        return dp[0][0];




    }
}; 
