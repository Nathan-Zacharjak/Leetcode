class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCount = 0;
        for (const auto& pos: position){
            if (pos % 2){
                oddCount++;
            }
        }
        return min(oddCount, (int)position.size() - oddCount);
    }
};