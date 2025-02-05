class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long lastOddMaxScore = nums[0];
        long long lastEvenMaxScore = nums[0];

        if (nums[0] % 2){
            lastEvenMaxScore -= x;
        } else {
            lastOddMaxScore -= x;
        }

        for (auto i = 1; i < nums.size(); i++){
            if (nums[i] % 2){
                lastOddMaxScore = max(lastEvenMaxScore - x, lastOddMaxScore) + nums[i];
            } else {
                lastEvenMaxScore = max(lastOddMaxScore - x, lastEvenMaxScore) + nums[i];
            }
        }

        return max(lastOddMaxScore, lastEvenMaxScore);
    }
};