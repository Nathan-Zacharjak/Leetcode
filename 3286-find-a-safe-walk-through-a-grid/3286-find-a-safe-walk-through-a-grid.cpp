class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int columns = grid[0].size();
        // cout << "rows: " << rows << ", columns: " << columns << '\n';

        unordered_map<int, unordered_set<int>> exploredCells;

        priority_queue<tuple<int, int, int>> q;
        if (grid[0][0] == 1){
            health--;
            if (health == 0) return false;
        }
        q.push({health,0,0});
        exploredCells[0].insert(0);

        vector<pair<int,int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()){
            auto [currHealth, x, y] = q.top();
            q.pop();

            // cout << "\nNext element: " << '\n';
            // cout << "health: " << currHealth << ", x:" << x << ", y:" << y << "\n\n";
            
            for (const auto& [xDiff, yDiff]: directions){
                int newX = x + xDiff;
                // cout << "\nnewX: " << newX << '\n';
                // cout << "newX < 0 ? "  << (newX < 0) << ", newX >= columns ? " << (newX >= columns) << '\n';
                if (newX < 0 || newX >= columns) continue;

                int newY = y + yDiff;
                // cout << "newY: " << newY << '\n';
                // cout << "newY < 0 ? "  << (newY < 0) << ", newY >= rows ? " << (newY >= rows) << '\n';
                if (newY < 0 || newY >= rows) continue;

                // cout << "Already explored? " << (exploredCells[newX].contains(newY)) << '\n';
                if (exploredCells[newX].contains(newY)) continue;

                int newHealth = currHealth - grid[newY][newX];

                // cout << "Health is 0? " << (newHealth < 1) << '\n';
                if (newHealth < 1) continue;

                // cout << "Is target cell? " << (newX == columns - 1 && newY == rows - 1) << '\n';
                if (newX == columns - 1 && newY == rows - 1) return true;

                // cout << "Pushing: " << newHealth << " " << newX << " " << newY << '\n';
                q.push({newHealth, newX, newY});
                exploredCells[newX].insert(newY);
            }
        }

        return false;
    }
};