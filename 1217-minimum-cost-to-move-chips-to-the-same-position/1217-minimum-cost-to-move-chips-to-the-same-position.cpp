class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        array<int, 2> counts;
        for (const auto& pos: position) counts[pos % 2]++;
        return min(counts[0], counts[1]);
    }
};