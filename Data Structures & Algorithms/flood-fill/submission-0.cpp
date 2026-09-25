class Solution {
public:
    void bfs(vector<vector<bool>>& vis, vector<vector<int>>& img, int sr, int sc, int color){
        queue<pair<pair<int, int>, int>> q;
        int c;

        q.push({{sr, sc}, img[sr][sc]});
        vis[sr][sc] = true;
        img[sr][sc] = color;

        while(q.size() > 0){
            int i = q.front().first.first;
            int j = q.front().first.second;
            c = q.front().second;
            q.pop();

            if((i-1) >=0 && !vis[i-1][j] && img[i-1][j] == c){
                q.push({{i-1, j}, img[i-1][j]});
                vis[i-1][j] = true;
                img[i-1][j] = color;
                
            }
            if((j-1) >= 0 && !vis[i][j-1] && img[i][j-1] == c){
                q.push({{i, j-1}, img[i][j-1]});
                vis[i][j-1] = true;
                img[i][j-1] = color;
                
            }
            if((i+1) < img.size() && !vis[i+1][j] && img[i+1][j] == c){
                q.push({{i+1, j}, img[i+1][j]});
                vis[i+1][j] = true;
                img[i+1][j] = color;
                
            }
            if((j+1) < img[0].size() && !vis[i][j+1] && img[i][j+1] == c){
                q.push({{i, j+1}, img[i][j+1]});
                vis[i][j+1] = true;
                img[i][j+1] = color;
            }
        }
        
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<bool>> vis(image.size(), vector<bool>(image[0].size(), false));
        bfs(vis, image, sr, sc, color);

        return image;
    }
};