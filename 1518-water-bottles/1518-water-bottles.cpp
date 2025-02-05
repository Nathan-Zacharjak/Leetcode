#include <print>

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int bottlesDrunk = 0;
        int emptyBottles = 0;
        int fullBottles = numBottles;

        do {
            println("bottlesDrunk: {}, emptyBottles: {}, numBottles: {}, numExchange: {}", bottlesDrunk, emptyBottles, numBottles, numExchange);
            bottlesDrunk += fullBottles;
            emptyBottles += fullBottles;

            fullBottles = emptyBottles / numExchange;
            emptyBottles = emptyBottles % numExchange;
            println("bottlesDrunk: {}, emptyBottles: {}, numBottles: {}, numExchange: {}\n", bottlesDrunk, emptyBottles, numBottles, numExchange);
        } while (fullBottles > 0);

        println("bottlesDrunk: {}, emptyBottles: {}, numBottles: {}, numExchange: {}", bottlesDrunk, emptyBottles, numBottles, numExchange);
        return bottlesDrunk;
    }
};