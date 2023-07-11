class Solution {
public:
    int uniquePaths(int totalRows, int totalCols) {
        // Tabulation question
        vector<vector<int>> dp(totalRows,vector<int>(totalCols,1));

        for(int rowIndex = 0; rowIndex < totalRows; rowIndex++ ){
            for(int colIndex = 0; colIndex < totalCols; colIndex++ ){

                if(rowIndex == 0 && colIndex == 0){
                    dp[rowIndex][colIndex] = 1;
                    continue;
                }

                int topAnswer = 0;
                if(rowIndex -1 >= 0 ){
                    // go top

                    topAnswer = dp[rowIndex-1][colIndex];
                }
                int leftAnswer = 0;
                if(colIndex -1 >= 0 ){
                    // go left

                    leftAnswer = dp[rowIndex][colIndex-1];
                } 

                dp[rowIndex][colIndex] = leftAnswer + topAnswer;
            }
        }

        return dp[totalRows-1][totalCols-1];
    }
};

