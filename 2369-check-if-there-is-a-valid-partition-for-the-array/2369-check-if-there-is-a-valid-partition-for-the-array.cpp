class Solution {
private:
    bool DPHelper(const vector<int>& nums, const int& start, vector<int>& DPArray) {
        if (start == nums.size()) return true;

        if (DPArray[start] != -1) return DPArray[start];

        bool is2Equal = false;
        bool is3Equal = false;
        bool is3Increasing = false;

        if (nums.size() > start + 1 && nums[start] == nums[start + 1]){
            is2Equal = DPHelper(nums, start + 2, DPArray);
        }
        if (nums.size() > start + 2 && nums[start] == nums[start + 1] && nums[start] == nums[start + 2]){
            is3Equal = DPHelper(nums, start + 3, DPArray);
        }
        if (nums.size() > start + 2 && nums[start] == nums[start + 1] - 1 && nums[start + 1] == nums[start + 2] - 1){
            is3Increasing = DPHelper(nums, start + 3, DPArray);
        }

        return DPArray[start] = is2Equal || is3Equal || is3Increasing;
    }

public:
    bool validPartition(const vector<int>& nums, const int& start = 0) {
        vector<int> DPArray(nums.size(), -1);

        return DPHelper(nums, 0, DPArray);
    }
};