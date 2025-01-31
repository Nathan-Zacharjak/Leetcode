class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        if (grid[0][0] == 1){
            health--;
            if (health == 0) return false;
        }

        int rows = grid.size();
        int columns = grid[0].size();

        vector<vector<int>> highestHealth(rows, vector<int>(columns, 0));
        highestHealth[0][0] = health;
        priority_queue<array<int, 3>> pq;
        pq.push({health,0,0});

        vector<array<int, 2>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!pq.empty()){
            auto [currHealth, currX, currY] = pq.top(); pq.pop();
            
            for (const auto& [dx, dy]: directions){
                int x = currX + dx;
                int y = currY + dy;
                if (min(x, y) < 0 || rows <= x || columns <= y) continue;

                int newHealth = currHealth - grid[x][y];
                if (highestHealth[x][y] < newHealth){
                    if (x == rows - 1 && y == columns - 1) return true;

                    highestHealth[x][y] = newHealth;
                    pq.push({newHealth, x, y});
                }
            }
        }

        return false;
    }
};