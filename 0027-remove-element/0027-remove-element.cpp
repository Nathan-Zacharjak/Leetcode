class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int keepIndex = 0;
        for (auto i = 0; i < nums.size(); i++){
            if (nums[i] != val){
                swap(nums[i], nums[keepIndex]);
                keepIndex++;
            }
        }
        return keepIndex;
    }
};