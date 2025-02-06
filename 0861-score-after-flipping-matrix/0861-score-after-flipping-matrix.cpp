class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        // Try to make each number as large as possible
        // Each row has as many 1s to the left as possible
        int m = grid.size();
        int n = grid[0].size();
        vector<int> oneCounts(n, 0);

        for (auto& row: grid){
            bool firstZero = row[0] == 0;

            for (auto i = 0; i < n; i++){
                if (firstZero){
                    row[i] = row[i] == 0 ? 1 : 0;
                }
                if (row[i] == 1) oneCounts[i]++;
            }
        }

        // Try to make each column have as many 1s as possible
        int score = 0;
        int powerOf2 = 1 << n - 1;

        for (const auto& count: oneCounts){
            int bestCount = max(m - count, count);
            score += powerOf2 * bestCount;
            powerOf2 = powerOf2 >> 1;
        }

        return score;
    }
};