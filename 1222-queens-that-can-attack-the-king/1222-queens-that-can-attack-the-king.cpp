class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        unordered_set<string> queenSet;
        for (const auto &queen : queens){
            queenSet.insert(to_string(queen[0]) + to_string(queen[1]));
        }

        vector<vector<int>> directions = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
        // N, NE, E, SE, S, SW, W, NW
        array<bool, 8> blockedDirections = {false};
        int blockedCount = 0;
        vector<vector<int>> unblockedQueens;

        for (int i = 1; i < 8; i++){
            for (int dirIndex = 0; dirIndex < 8; dirIndex++){
                if (blockedDirections.at(dirIndex)){
                    if (blockedCount == 8){
                        return unblockedQueens;
                    }
                    continue;
                }
                int x = directions[dirIndex][0] * i + king[0];
                int y = directions[dirIndex][1] * i + king[1];
                string coords = to_string(x) + to_string(y);

                if (queenSet.contains(coords)){
                    blockedDirections.at(dirIndex) = true;
                    blockedCount++;
                    unblockedQueens.push_back({x, y});
                }
            }
        }

        return unblockedQueens;
    }
};