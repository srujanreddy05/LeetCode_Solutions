class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, -1));

        queue<pair<int, int>> q;

        q.push({0, 0});
        dist[0][0] = 1;

        int directions[8][2] = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if (row == n - 1 && col == n - 1)
                return dist[row][col];

            for (auto& dir : directions) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 &&
                    dist[newRow][newCol] == -1) {

                    dist[newRow][newCol] = dist[row][col] + 1;

                    q.push({newRow, newCol});
                }
            }
        }

        return -1;
    }
};