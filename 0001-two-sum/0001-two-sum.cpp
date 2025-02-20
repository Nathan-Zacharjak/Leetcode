class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numToIndex;

        for (auto i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if (numToIndex.contains(complement)) return {i, numToIndex[complement]};
            numToIndex[nums[i]] = i;
        }

        return {};
    }
};