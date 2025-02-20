// #include <print>

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // println("n: {}, m: {}", n, m);
        unordered_map<int, pair<int,int>> valToCoord;

        for (auto i = 0; i < n; i++){
            for (auto j = 0; j < m; j++){
                valToCoord[mat[i][j]] = {i,j};
            }
        }

        // for (const auto& [val, coords]: valToCoord){
        //     println("val: {}, row: {}, col: {}", val, coords.first, coords.second);
        // }

        vector<int> rowPaintCount(n,0);
        vector<int> colPaintCount(m,0);

        for (auto i = 0; i < arr.size(); i++){
            auto [row,col] = valToCoord[arr[i]];
            rowPaintCount[row]++;
            colPaintCount[col]++;
            // println("\n\ni: {}, row: {}, col: {}", i, row, col);
            // println("Row paint count:");
            // for (auto j = 0; j < rowPaintCount.size(); j++){
            //     print("{}: {} ", j, rowPaintCount[j]);
            // }
            // println("\nCol paint count:");
            // for (auto j = 0; j < colPaintCount.size(); j++){
            //     print("{}: {} ", j, colPaintCount[j]);
            // }
            if (rowPaintCount[row] == m || colPaintCount[col] == n) return i;
        }

        return -1;
    }
};