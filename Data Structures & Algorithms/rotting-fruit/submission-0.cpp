class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rowLen = grid.size();
        int colLen = grid[0].size();
        int ans = 0;

        vector<vector<bool>> vis(rowLen, vector<bool>(colLen, false));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    vis[i][j] = true;
                }
            }
        }

        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();

            ans = max(time, ans);

            if(i+1 < rowLen && grid[i+1][j] == 1 && !vis[i+1][j]){
                q.push({{i+1, j}, time+1});
                vis[i+1][j] = true;
            }
            if(j+1 < colLen && grid[i][j+1] == 1 && !vis[i][j+1]){
                q.push({{i, j+1}, time+1});
                vis[i][j+1] = true;
            }
            if(i-1 >= 0 && grid[i-1][j] == 1 && !vis[i-1][j]){
                q.push({{i-1, j}, time+1});
                vis[i-1][j] = true;
            }
            if(j-1 >= 0 && grid[i][j-1] == 1 && !vis[i][j-1]){
                q.push({{i, j-1}, time+1});
                vis[i][j-1] = true;
            }
        }

        for(int i = 0; i < rowLen; i++){
            for(int j = 0; j < colLen; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    return -1;
                }
            }
        }

        return ans;
    }
};
