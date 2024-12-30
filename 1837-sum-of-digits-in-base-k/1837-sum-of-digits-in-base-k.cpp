class Solution {
public:
    int sumBase(int n, int k) {
        // Convert to base k:
        int currentNumber = n;
        int baseKNum = 0;
        int timesLargestPowerFits = -1;

        while (timesLargestPowerFits != 0){
            // Find the largest power of k that fits into n
            int largestFittingPower = 1;

            while (currentNumber / (largestFittingPower * k) >= 1){
                largestFittingPower *= k;
            }

            // Find how many times that power fits into n
            timesLargestPowerFits = currentNumber / largestFittingPower;
            // Insert that number as the right-most digit, times running sum by 10 and add that number
            baseKNum = baseKNum * 10 + timesLargestPowerFits;
            // Find the remainder
            int remainder = currentNumber % largestFittingPower;
            // Make the current number equal to the remainder
            currentNumber = remainder;
            // Continue until current number equals 0
        }


        // Sum the digits:
        int runningSum = 0;
        int currentNum = baseKNum;

        while (currentNum != 0){
            // Take the modulo 10 of the number
            int currentDigit = currentNum % 10;
            // Add the remainder to a running sum
            runningSum += currentDigit;
            // Divide the original number by 10 and round down
            currentNum /= 10;
            // Continue until original number = 0
        }

        // Return running sum
        return runningSum;
    }
};