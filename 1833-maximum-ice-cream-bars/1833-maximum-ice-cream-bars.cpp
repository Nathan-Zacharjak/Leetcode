class Solution {
public:
    int maxIceCream(vector<int>& costs, int& coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> costCounts(maxCost + 1, 0);

        for (const auto& cost: costs) costCounts[cost]++;

        int boughtCount = 0;
        for (auto i = 1; i <= maxCost; i++){
            if (costCounts[i] == 0) continue;
            if (coins < i) break;

            int count = min(costCounts[i], coins/i);
            boughtCount += count;
            coins -= count * i;
        }

        return boughtCount;
    }
};