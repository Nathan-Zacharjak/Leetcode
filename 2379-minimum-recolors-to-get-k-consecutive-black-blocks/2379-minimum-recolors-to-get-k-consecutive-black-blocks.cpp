class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        // Keep track of back and front index, min value so far, and the current cost for this window
        int front, back, currentCost;
        front = back = currentCost = 0;
        int runningMin = k;

        // While we're still in the blocks string,
        while (front < blocks.size()){
            // If the current char of front is white, add 1 to the current cost
            if (blocks.at(front) == 'W'){
                currentCost++;
            }

            // If the window has reached max size, start checking
            if (front - back + 1 == k){
                // If the current cost is less than the min cost so far, update it!
                runningMin = min(runningMin, currentCost);

                // Take away back's cost from current cost if it is a white char
                if (blocks.at(back) == 'W'){
                    currentCost--;
                }

                // Increment back by 1
                back++;
            }

            // Increment front by 1
            front++;
        }

        // Return the running min!
        return runningMin;
    }
};