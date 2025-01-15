class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (k == 0){
            return false;
        }

        unordered_set<int> windowNums;
        windowNums.insert(nums[0]);

        int start = 0;
        int end = 1;
        int numsSize = nums.size();

        while (end < numsSize){
            if (windowNums.contains(nums[end])){
                return true;
            } else {
                windowNums.insert(nums[end]);
            }

            if (end - start < k){
                end++;
            } else {
                windowNums.erase(nums[start]);
                start++;
                end++;
            }
        }

        return false;
    }
};