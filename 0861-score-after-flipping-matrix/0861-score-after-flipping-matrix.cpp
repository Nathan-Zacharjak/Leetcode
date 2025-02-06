class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // All of first column is 1
        int count = (1 << n-1) * m;

        for (auto j = 1; j < n; j++){
            int oneCount = 0;
            for (auto i = 0; i < m; i++){
                if (grid[i][0] == grid[i][j]) oneCount++;
            }
            // Choose to flip column or not
            oneCount = max(oneCount, m - oneCount);
            count += (1 << n - j - 1) * oneCount;
        }

        return count;
    }
};