class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (const auto& num: nums){

            if (lis.empty() || lis.back() < num){
                lis.push_back(num);
                continue;
            }
            if (lis.back() == num || lis.front() == num) continue;

            int left = 0, right = lis.size() - 1, middle = -1;
            while (left < right){
                middle = left + (right - left)/2;

                if (lis[middle] < num){
                    left = middle + 1;
                } else {
                    right = middle;
                }
            }
            
            lis[left] = num;
        }

        return lis.size();
    }
};