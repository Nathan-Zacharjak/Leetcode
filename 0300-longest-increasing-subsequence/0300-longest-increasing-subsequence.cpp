// #include <print>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> fakeLIS;
        vector<int> fakeLISIndexes;
        vector<int> ancestors(nums.size(), -1);
        
        for (auto i = 0; i < nums.size(); i++){
            int num = nums[i];

            if (fakeLIS.empty() || fakeLIS.back() < num){
                if (!fakeLIS.empty()){
                    // Because the current number is building a new longest subsequence
                    // We can just link back to the last index we inserted, that will be the previous number in the sequence
                    ancestors[i] = fakeLISIndexes.back();
                }

                fakeLIS.push_back(num);
                fakeLISIndexes.push_back(i);
                continue;
            }
            if (fakeLIS.back() == num || fakeLIS.front() == num) continue;

            int left = 0, right = fakeLIS.size() - 1, middle = -1;
            while (left < right){
                middle = left + (right - left)/2;

                if (fakeLIS[middle] < num){
                    left = middle + 1;
                } else {
                    right = middle;
                }
            }

            // So, if we're wanting to create a new subsequence branch,
            // we need to make the current number's ancestor the last number smaller than it
            // this is given by the number before the one the binary search returns

            // Also, if the current number is smaller than all numbers seen in the sequence so far, we just have a brand new sequence,
            // so since the ancestors array got intilised to -1s, we can just skip trying to find the first valid number to make the new sequence
            if (left > 0){
                // since the binary search gives the first invalid number's index, the first valid number will be 1 before this
                ancestors[i] = fakeLISIndexes[left - 1];
            }
            
            fakeLIS[left] = num;
            fakeLISIndexes[left] = i;
        }

        // println("Fake LIS:");
        // for (const auto& n: fakeLIS){
        //     print("{} ", n);
        // }
        // print("\n");

        // println("Fake LIS Indexes:");
        // for (const auto& n: fakeLISIndexes){
        //     print("{} ", n);
        // }
        // print("\n");

        // println("Ancestors:");
        // for (auto i = 0; i < ancestors.size(); i++){
        //     println("numsIndex: {} ancestor: {}", i, ancestors[i]);
        // }
        // print("\n");

        int currentIndex = fakeLISIndexes.back();
        vector<int> lis;
        while (currentIndex != -1){
            lis.push_back(nums[currentIndex]);
            currentIndex = ancestors[currentIndex];
        }
        reverse(lis.begin(), lis.end());

        // println("LIS:");
        // for (const auto& n: lis){
        //     print("{} ", n);
        // }
        // print("\n");

        return fakeLIS.size();
    }
};