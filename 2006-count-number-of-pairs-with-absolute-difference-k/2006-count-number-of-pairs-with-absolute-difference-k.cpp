class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        vector<int> valueCount(101);
        for (const auto& num: nums) valueCount[num]++;

        int result = 0;

        for (int i = 0; i < 101 - k; i++){
            result += valueCount[i] * valueCount[i + k];
        }

        return result;
    }
};