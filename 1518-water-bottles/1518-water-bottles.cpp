class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int bottlesDrunk = 0;
        int emptyBottles = 0;
        int fullBottles = numBottles;

        do {
            bottlesDrunk += fullBottles;
            emptyBottles += fullBottles;

            fullBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;
        } while (fullBottles > 0);

        return bottlesDrunk;
    }
};