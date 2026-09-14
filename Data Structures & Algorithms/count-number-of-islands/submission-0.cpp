class Solution {
private:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j, int& rowLen, int& colLen){
        if(i < 0 || j < 0 || i >= rowLen || j >= colLen) return;
        if(grid[i][j] == '0' || vis[i][j]) return;

        vis[i][j] = true;

        dfs(grid, vis, i+1, j, rowLen, colLen);
        dfs(grid, vis, i, j+1, rowLen, colLen);
        dfs(grid, vis, i-1, j, rowLen, colLen);
        dfs(grid, vis, i, j-1, rowLen, colLen);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        int numberOfIsland = 0;

        vector<vector<bool>> vis(rowLen, vector<bool>(colLen, false));

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    dfs(grid, vis, i, j, rowLen, colLen);
                    numberOfIsland++;
                }
            }
        }
        return numberOfIsland;
    }
};
