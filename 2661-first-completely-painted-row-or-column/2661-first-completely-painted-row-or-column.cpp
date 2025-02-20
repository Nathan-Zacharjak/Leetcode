class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, int> numToIndex;

        for (auto i = 0; i < arr.size(); i++){
            numToIndex[arr[i]] = i;
        }

        int result = arr.size();

        for (auto row = 0; row < n; row++){
            int maxPaintIndex = -1;
            for (auto col = 0; col < m; col++){
                int index = numToIndex[mat[row][col]];
                maxPaintIndex = max(maxPaintIndex, index);
            }
            result = min(result, maxPaintIndex);
        }

        for (auto col = 0; col < m; col++){
            int maxPaintIndex = -1;
            for (auto row = 0; row < n; row++){
                int index = numToIndex[mat[row][col]];
                maxPaintIndex = max(maxPaintIndex, index);
            }
            result = min(result, maxPaintIndex);
        }

        return result;
    }
};