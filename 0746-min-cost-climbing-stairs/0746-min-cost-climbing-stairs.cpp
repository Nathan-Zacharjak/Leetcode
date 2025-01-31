class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int evenCost = cost[0];
        int oddCost = cost[1];

        for (int i = 2; i < cost.size(); i++){
            if (i % 2 == 0){
                evenCost = min(evenCost, oddCost) + cost[i];
            } else {
                oddCost = min(evenCost, oddCost) + cost[i];
            }
        }

        return min(evenCost, oddCost);
    }
};