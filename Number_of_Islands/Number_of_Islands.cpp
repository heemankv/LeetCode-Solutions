class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int r, int c, int trows, int tcols)
    {
        // as soon as you land
        // mark element visited
        vis[r][c] = true;

        // get dx, dy
        int dx[4] = {0,0,1,-1};
        int dy[4] = {1,-1,0,0};

        // do nested loop and call dfs on all that are not visited    
        for(int i = 0 ; i < 4; i++){
            int newRow = r + dx[i];
            int newCol = c + dy[i];
            if(newRow >= 0 && newCol >= 0 &&  newCol < tcols && newRow < trows){
                if(!vis[newRow][newCol] && grid[newRow][newCol] == '1' ){
                    dfs(grid,vis,newRow,newCol,trows,tcols);
                }
            }
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int trows = grid.size();
        int tcols = grid[0].size();
        // initialise things    
        vector<vector<bool>> vis(trows,vector<bool>(tcols,false));
        // initially none is visited

        // init count
        int count = 0;

        // go to all the elements in the matrix 
        //rows
        for(int r = 0; r < trows; r++ ){
            // cols
            for(int c = 0 ; c < tcols; c++){
                // go to element if not visited and mark it visited
                if(grid[r][c] == '1' && !vis[r][c]){
                    cout<<r<<c<<endl;
                    dfs(grid,vis,r,c,trows,tcols);
                    count++;
                }
            }
        }

        return count;
    }
};
