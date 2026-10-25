class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue <pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if (grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int minutes = 0;
        int directions[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty() && fresh > 0){
            int size = q.size();

            for(int i = 0 ; i < size;i++){
                auto [row,col] = q.front();
                q.pop();
            for(auto& dir : directions){
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == 1){
                    grid[newRow][newCol] = 2;
                    fresh--;
                    q.push({newRow,newCol});
                }
            }
            
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};