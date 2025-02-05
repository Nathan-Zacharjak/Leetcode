class Solution {
public:
    int rob(vector<int>& nums) {
        int maxChoose = nums[0];
        int maxSkip = 0;

        for (auto i = 1; i < nums.size(); i++){
            int chooseChoose = maxChoose - nums[i - 1] + nums[i];
            int skipChoose = maxSkip + nums[i];
            int chooseSkip = maxChoose;
            int skipSkip = maxSkip;

            maxChoose = max(chooseChoose, skipChoose);
            maxSkip = max(chooseSkip, skipSkip);
        }

        return max(maxChoose, maxSkip);
    }
};