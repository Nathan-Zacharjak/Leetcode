class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        for (int i = 0; i < nums.size(); i++){
            if (window.contains(nums[i])){
                return true;
            }
            window.insert(nums[i]);

            if (window.size() > k){
                window.erase(nums[i - k]);
            }
        }
        return false;
    }
};