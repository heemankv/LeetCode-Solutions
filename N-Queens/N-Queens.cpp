class Solution {
public:
    bool isSafe(vector<string> &board, int col, int row, int n){

     
        // check for upper left diagonal
        int irow = row;
        int icol = col;
        while (irow >= 0 && icol >= 0) {
            if (board[irow][icol] == 'Q') return false;
            irow--;
            icol--;
        }


        // check for left hr
        irow = row;
        icol = col;
        while (icol >= 0) {
            if (board[irow][icol] == 'Q') return false;
            icol--;
        }

        
        // check for bottom left diagonal
        irow = row;
        icol = col;
        while(irow < n && icol >= 0){
            if(board[irow][icol] == 'Q'){
                return false;
            }
            irow++;
            icol--;  // corrected from icol--;
        }
        return true;
    }



    void solve(vector<vector<string>> &answer, vector<string> &board, int col, int n){

        // if I have tried for all my columns and i am going for the nth one then I have filled all n-1     
        // queens and thus my answer is in board

        if(col == n){
            answer.push_back(board);
            return;
        }

        // now for the current column I'll try to place on all the rows
        // loop
        for(int i = 0 ; i < n ; i++){
            // I'll check if it's safe to put on that row,
            // If yes ? 
            // then put and call on next col, col + 1
            // If not safe ?
            // then go try next row in this column // i.e do nothing
            if(isSafe(board,col,i,n)){
                board[i][col] = 'Q';
                solve(answer, board, col + 1, n);
                board[i][col] = '.';
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer; // final answer 
        vector<string> board(n, string(n, '.')); // temp answer that gets dumped
        solve(answer, board, 0, n);
        return answer;
    }
};
