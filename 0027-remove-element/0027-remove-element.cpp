#include <print>

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

        for (const auto & num: nums) print("{} ", num);
        print("\n");
        for (auto i = 0; i < nums.size(); i++) print("{} ", i);
        print("\n");

        if (removeSize > 0){
            for (auto i = nums.size() - 1; i >= 0; i--){
                println("Swapping: {}, and, {}, at indexes: {}, and {}", nums[i], nums[removeStartIndex + removedCount], i, removeStartIndex + removedCount);
                swap(nums[i], nums[removeStartIndex + removedCount]);
                removedCount++;
                if (removedCount >= removeSize || removeStartIndex + removedCount >= nums.size()) break;
            }
        }

        return nums.size() - removeSize;
    }
};