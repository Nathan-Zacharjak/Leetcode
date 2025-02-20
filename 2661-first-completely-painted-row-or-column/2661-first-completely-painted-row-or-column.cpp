class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, pair<int,int>> valToCoord;

        for (auto i = 0; i < n; i++){
            for (auto j = 0; j < m; j++){
                valToCoord[mat[i][j]] = {i,j};
            }
        }

        vector<int> rowPaintCount(n,0);
        vector<int> colPaintCount(m,0);

        for (auto i = 0; i < arr.size(); i++){
            auto [row,col] = valToCoord[arr[i]];
            rowPaintCount[row]++;
            colPaintCount[col]++;
            if (rowPaintCount[row] == m || colPaintCount[col] == n) return i;
        }

        return -1;
    }
};