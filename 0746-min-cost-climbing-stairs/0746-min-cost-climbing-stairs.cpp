class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> minCosts(n);
        minCosts[0] = cost[0];
        minCosts[1] = cost[1];

        for (int i = 2; i < n; i++){
            minCosts[i] = min(minCosts[i - 1], minCosts[i - 2]) + cost[i];
        }

        return min(minCosts[cost.size() - 1], minCosts[cost.size() - 2]);
    }
};