class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> valueCount;
        for (const auto& num: nums) valueCount[num]++;

        int result = 0;

        for (const auto& [value, count]: valueCount){
            if (valueCount.contains(value + k)){
                result += count * valueCount[value + k];
            }
        }

        return result;
    }
};