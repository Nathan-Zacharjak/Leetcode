class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;

        if (nums.size() == 1){
            if (nums[0] == val) {
                return 0;
            } else {
                return 1;
            }
        }

        sort(nums.begin(), nums.end());

        int removeSize = 0;
        int removeStartIndex = -1;

        for (auto i = 0; i < nums.size(); i++){
            if (nums[i] == val){
                if (removeStartIndex == -1){
                    removeStartIndex = i;
                }
                removeSize++;
            }
        }

        int removedCount = 0;

        if (removeSize > 0){
            for (auto i = nums.size() - 1; i >= 0; i--){
                swap(nums[i], nums[removeStartIndex + removedCount]);
                removedCount++;
                if (removedCount >= removeSize || removeStartIndex + removedCount >= nums.size()) break;
            }
        }

        return nums.size() - removeSize;
    }
};