class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer(2, -1);
        unordered_map<int, unordered_set<int>> numToIndexes;

        for (auto i = 0; i < nums.size(); i++){
            numToIndexes[nums[i]].insert(i);
        }

        for (auto i = 0; i < nums.size(); i++){
            int num = nums[i];
            int complement = target - num;

            if (numToIndexes.contains(complement)){
                int nonSameIndex = -1;

                for (const auto& index: numToIndexes[complement]){
                    if (index != i){
                        answer = {i, index};
                        return answer;
                    }
                }
            }
        }

        return answer;
    }
};