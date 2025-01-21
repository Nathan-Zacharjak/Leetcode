class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        // If k goes off the edge at any point, i is not a good index
        // Need linear time
        int n = nums.size();
        vector<int> beforePrefix(n, 0);
        int beforePrefixIndex = 0;
        vector<int> afterPrefix(n, 0);
        int afterPrefixIndex = 0;

        for (int i = 0; i < n - 1; i++){
            if (nums[i] < nums[i + 1]){
                beforePrefixIndex++;
            } else if (nums[i] > nums[i + 1]){
                afterPrefixIndex++;
            }
            beforePrefix[i + 1] = beforePrefixIndex;
            afterPrefix[i + 1] = afterPrefixIndex;
        }

        int start = 0;
        int end = 0;
        vector<int> result;

        for (int i = 1; i < n - 1; i++){
            start = i - k;
            end = i + k;
            if (start < 0 || end >= n){
                continue;
            }

            if (beforePrefix[start] - beforePrefix[i - 1] == 0 && afterPrefix[i + 1] - afterPrefix[end] == 0){
                result.push_back(i);
            }
        }

        return result;
    }
};