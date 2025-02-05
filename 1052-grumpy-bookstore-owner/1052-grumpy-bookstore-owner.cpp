// #include <print>

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // Non-grumpy minute customers are always satisfied
        // Can just add all customers in non-grumpy minutes

        // Want the maximum grumpy customers in a minutes-wide window
        // Add the non-grumpy customers to the total, and set them to 0 in the customers array

        // Initially add the window total of grumpy customers
        // Left = right = 0
        int left = 0;
        int right = 0;
        int nonGrumpyCount = 0;
        int windowCount = 0;
        int maxWindowCount = 0;
        int n = customers.size();

        // while right - left < minutes
        while (right < n){
            // Once right - left == minutes, and so long as right < n,
            if (right - left >= minutes){
                // minus customers[left] from window total
                windowCount -= customers[left];
                // left++
                left++;
            }

            // If customers[right] is not grumpy, add to answer, set to 0
            if (grumpy[right] == 0){
                nonGrumpyCount += customers[right];
                customers[right] = 0;
            } else {
                // If customers[right] is grumpy, add to window total
                windowCount += customers[right];
                // If window total is max seen, update max window total
                maxWindowCount = max(maxWindowCount, windowCount);
            }
            // println("left: {}, right: {}, nonGrumpyCount: {}, windowCount: {}, maxWindowCount: {}", left, right, nonGrumpyCount, windowCount, maxWindowCount);
            // right++
            right++;

        }

        // Add max window count to the total, and return
        return maxWindowCount + nonGrumpyCount;
    }
};