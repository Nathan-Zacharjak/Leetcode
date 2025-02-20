class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int size = n * m;

        vector<int> valToRow(size + 1);
        vector<int> valToCol(size + 1);

        for (auto row = 0; row < n; row++){
            for (auto col = 0; col < m; col++){
                int val = mat[row][col];
                valToRow[val] = row;
                valToCol[val] = col;
            }
        }
        vector<int> rowCount(n);
        vector<int> colCount(m);

        for (auto i = 0; i < size; i++){
            int val = arr[i];
            rowCount[valToRow[val]]++;
            colCount[valToCol[val]]++;

            if (rowCount[valToRow[val]] == m || colCount[valToCol[val]] == n) return i;
        }

        return -1;
    }
};