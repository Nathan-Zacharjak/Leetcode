class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> numToIndex;
        for (auto i = 0; i < nums.size(); i++) numToIndex[nums[i]] = i;

        for (const auto& op: operations){
            int fromNum = op[0];
            int toNum = op[1];

            int index = numToIndex[fromNum];
            nums[index] = toNum;
            numToIndex.erase(fromNum);
            numToIndex[toNum] = index;
        }

        return nums;
    }
};