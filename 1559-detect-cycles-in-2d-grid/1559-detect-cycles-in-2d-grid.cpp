class Solution {
private:
    bool DFS(const int& row, const int& col, vector<vector<bool>>& visited, const vector<pair<int, int>>& directions, const vector<vector<char>>& grid, const int& lastRow, const int& lastCol){
        visited[row][col] = true;

        for (const auto &[x, y] : directions){
            int newRow = row + x;
            if (newRow < 0 || newRow >= grid.size()){
                continue;
            }

            int newCol = col + y;
            if (newCol < 0 || newCol >= grid[0].size() || (newRow == lastRow && newCol == lastCol)){
                continue;
            }

            if (grid[newRow][newCol] == grid[row][col]){
                if (visited[newRow][newCol]){
                    return true;
                } else if (DFS(newRow, newCol, visited, directions, grid, row, col)){
                    return true;
                }
            }
        }

        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        for (int row = 0; row < n; row++){
            for (int col = 0; col < m; col++){
                if (visited[row][col]){
                    continue;
                }

                if (DFS(row, col, visited, directions, grid, -1, -1)){
                    return true;
                }
            }
        }

        return false;
    }
};