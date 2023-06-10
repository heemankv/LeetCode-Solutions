class Solution {
public:


    bool isBoardFilled(const vector<vector<char>>& board) {
        for (const auto& row : board) {
            for (const char& digit : row) {
                if (digit == '.') {
                    return false;
                }
            }
        }
        return true;
    }


    bool isValid(vector<vector<char>>& board, int row, int col, char c){

        //  abhi I am just checking if it can be inserted, i haven't inserted abhi tak vese!
        //  how to check validation 
        //  in a single loop that goes from 0 to 9{

       


        for(int i = 0 ; i < 9; i++){

            if( board[i][col] == c){
                return false;
            }

            if( board[row][i] == c){
                return false;
            }


            if( board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c){
                return false;
            }

            // check for all elems in the column
            // check for all the elems in the row
            // check for all the elems in the block using 
            // board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c







        }
        return true;

        }









    bool solveSudoku(vector<vector<char>>& board) {

        if(isBoardFilled(board)){
            return true;
        }

        // We need to return the first possible solution to the sudoku problem

        // We will have to try all the possible comination on all the possible cases

        //  for all rows
            //  for all columns
                // if the value at board[i][j] is '.'
                // try putting values in board[i][j] from 0 to 9
                    // for loop to put values.
                        //  if the board is valid for the value 
                            // insert it
                            // call solveSudoku for new state of &board
                            // if that return is valid then return true stating that valid state is in the board
                    //  return false i. e we were unable to find a combination as sucn 
        // if all exits on last iteration 
        // we return true
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;

                            if (solveSudoku(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;  






        
    }
};
