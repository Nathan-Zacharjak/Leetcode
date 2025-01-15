class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        array<array<bool, 8>, 8> queenSet;
        for (const auto & queen : queens){
            queenSet[queen[0]][queen[1]] = true;
        }

        vector<vector<int>> result;

        for (int i = -1; i < 2; i++){
            for (int j = -1; j < 2; j++){
                for (int k = 1; k < 8; k++){
                    int x = king[0] + (i * k);
                    if (x > 7 || x < 0){
                        break;
                    }
                    int y = king[1] + (j * k);
                    if (y > 7 || y < 0){
                        break;
                    }
                    if (queenSet[x][y]){
                        result.push_back({x,y});
                        break;
                    }
                }
            }
        }
        
        return result;
    }
};