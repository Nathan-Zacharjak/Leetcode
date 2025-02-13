class Solution {
public:
    bool validPartition(const vector<int>& nums, const int& start = 0) {
        if (start == nums.size()) return true;

        // First check the first 2 elements if they are the same
        bool is2Equal = false;
        bool is3Equal = false;
        bool is3Increasing = false;

        if (nums.size() > start + 1 && nums[start] == nums[start + 1]){
            is2Equal = validPartition(nums, start + 2);
        }
        if (nums.size() > start + 2 && nums[start] == nums[start + 1] && nums[start] == nums[start + 2]){
            is3Equal = validPartition(nums, start + 3);
        }
        if (nums.size() > start + 2 && nums[start] == nums[start + 1] - 1 && nums[start + 1] == nums[start + 2] - 1){
            is3Increasing = validPartition(nums, start + 3);
        }

        return is2Equal || is3Equal || is3Increasing;
    }
};