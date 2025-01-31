class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int oddCount = 0;
        int evenCount = 0;
        for (const auto& pos: position){
            if (pos % 2){
                oddCount++;
            } else {
                evenCount++;
            }
        }
        return min(oddCount, evenCount);
    }
};