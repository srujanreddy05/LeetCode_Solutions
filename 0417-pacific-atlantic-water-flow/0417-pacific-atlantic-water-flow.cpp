class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& visited) {

        visited[r][c] = true;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for(int i = 0; i < 4; i++) {

            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= heights.size() ||
               nc < 0 || nc >= heights[0].size() ||
               visited[nr][nc] ||
               heights[nr][nc] < heights[r][c]) {
                continue;
            }

            dfs(nr, nc, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Left and Right borders
        for(int i = 0; i < m; i++) {
            dfs(i, 0, heights, pacific);
            dfs(i, n - 1, heights, atlantic);
        }

        // Top and Bottom borders
        for(int j = 0; j < n; j++) {
            dfs(0, j, heights, pacific);
            dfs(m - 1, j, heights, atlantic);
        }

        vector<vector<int>> result;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};