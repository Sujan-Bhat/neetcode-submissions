class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int row, int col, vector<vector<bool>>& vis){
        
        if(i < 0 || j < 0 || i >= row || j >= col || vis[i][j] || grid[i][j] == 0) return 0;

        vis[i][j] = true;

        int left = helper(grid, i, j-1, row, col, vis);
        int down = helper(grid, i-1, j, row, col, vis);
        int right = helper(grid, i+1, j, row, col, vis);
        int top = helper(grid, i, j+1, row, col, vis);
            
        return 1 + left + right + down + top;
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        vector<vector<bool>> vis(row, vector<bool>(col, false));
        int area = 0;
        int curArea;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    curArea = helper(grid, i, j, row, col, vis);
                    if(curArea > area){
                        area = curArea;
                    }
                }
            }
        }
        return area;
    }
};
