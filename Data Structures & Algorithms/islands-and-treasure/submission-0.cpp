class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        queue<pair<int,int>> q;

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j]==0) q.push({i,j});
            }
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                if(nr<0 || nc<0 || nr>=row || nc>=col || grid[nr][nc]==-1) continue;
                if (grid[nr][nc] > grid[r][c] + 1) {
                    grid[nr][nc] = grid[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

    }
};
