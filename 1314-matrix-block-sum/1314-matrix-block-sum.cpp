class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> prefix(m + 1, vector<int>(n + 1));
        
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                prefix[i] [j] = mat[i-1] [j-1] + prefix[i-1] [j] + prefix[i] [j-1] - prefix[i-1] [j-1];
        
        vector<vector<int>> ans(m, vector<int>(n));
        
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                int r1 = max(0, i - k), r2 = min(m - 1, i + k) + 1;
                int c1 = max(0, j - k), c2 = min(n - 1, j + k) + 1;
                ans[i] [j] = prefix[r2] [c2] - prefix[r1] [c2] - prefix[r2] [c1] + prefix[r1] [c1];
            }
        
        return ans;
    }
};