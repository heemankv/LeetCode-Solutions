class Solution {
private:
    void dfs(vector<vector<char>>& board,vector<vector<bool>>& vis, int r, int c, int trows, int tcols){
        // TODO: check against vis
        // mark the newly reached element
        vis[r][c] = true;
        // ask the element to check it's left right top bottom
        // 4 directions
        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};

        for(int i = 0 ; i < 4; i++){
            int newR = r + dx[i];
            int newC = c + dy[i];
            // ensure the indexes are healthy
            if(newR >= 0 && newR < trows && newC >=0 && newC < tcols){
                // ensure the next elem has 'O'
                if(board[newR][newC] == 'O' && !vis[newR][newC]){
                    dfs(board,vis,newR,newC,trows,tcols);
                }
            }
        }
        return;
    }

public:
    void solve(vector<vector<char>>& board) {
        // find trows, tcols
        int trows = board.size();
        int tcols = board[0].size();

        // need for visited array
        vector<vector<bool>> vis(trows, vector<bool>(tcols,false));
        // call for all 4 boundaries , 0th & last row, any columns
        for(int i = 0 ; i < tcols;i++){
            if( !vis[0][i] &&  board[0][i] == 'O'){
                //  call dfs
                dfs(board,vis, 0, i, trows, tcols);
            }

            if(!vis[trows-1][i] && board[trows-1][i] == 'O'){
                //  call dfs
                dfs(board,vis, trows-1, i, trows, tcols);
            }
        }

        // call for all 4 boundaries , 0th & last col, any rows
        for(int i = 0 ; i < trows;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                //  call dfs
                dfs(board,vis, i, 0, trows, tcols);
            }

            if(!vis[i][tcols-1] && board[i][tcols-1] == 'O'){
                //  call dfs
                dfs(board,vis, i, tcols-1, trows, tcols);
            }
        }
        // after visiting all the 4 boundaries,
        // run a loop for all the matrices, if an element is '0' but not visited mark it 'X' that is answer

        // loop over all the possibilities of element indexes
        for(int r = 0 ; r < trows; r++){
            for (int c = 0; c < tcols ; c++){
                // check and go
                if(!vis[r][c] && board[r][c] == 'O'){
                    //  call dfs
                    board[r][c] = 'X';
                }
            }
        }
        return;
    }
};





























