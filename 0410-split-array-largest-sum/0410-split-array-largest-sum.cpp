class Solution {
private:
    int minSplitsSoMaxSumIsLessThanOrEqualToGuess(const vector<int>& nums, const int& guess){
        int sumSoFar = 0;
        int splitCount = 0;

        for (const auto& num: nums){
            if (sumSoFar + num <= guess){
                sumSoFar += num;
            } else {
                sumSoFar = num;
                splitCount++;
            }
        }

        return splitCount;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0, plus<int>());
        if (k == 1) return sum;
        k--;
        int left = *max_element(nums.begin(), nums.end());
        int right = sum;
        int ans = -1;

        while (left <= right){
            int guess = left + (right - left) / 2;
            int minSplits = minSplitsSoMaxSumIsLessThanOrEqualToGuess(nums, guess);

            if (minSplits > k){
                left = guess + 1;
            } else {
                right = guess - 1;
                ans = guess;
            }
        }

        return ans;
    }
};