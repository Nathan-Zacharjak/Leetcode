class Solution {
public:
    int maxIceCream(vector<int>& costs, int& coins) {
        // int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> costCounts(1e5 + 1, 0);

        for (const auto& cost: costs) costCounts[cost]++;

        int count = 0;
        for (auto i = 1; i < costCounts.size(); i++){
            if (costCounts[i] == 0) continue;
            if (coins - i < 0) break;

            long long costCount = costCounts[i];
            long long buyAllCoins = coins - costCount * i;
            if (buyAllCoins > 0){
                coins = buyAllCoins;
                count += costCounts[i];
            } else {
                while (coins - i >= 0 && costCounts[i] > 0){
                    coins -= i;
                    count++;
                    costCounts[i]--;
                }
            }
        }

        return count;
    }
};