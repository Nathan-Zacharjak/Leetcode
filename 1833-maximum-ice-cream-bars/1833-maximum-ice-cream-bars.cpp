class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int count = 0;

        for (const auto& cost: costs){
            coins -= cost;
            if (coins < 0){
                break;
            } else {
                count++;
            }
        }
        
        return count;
    }
};