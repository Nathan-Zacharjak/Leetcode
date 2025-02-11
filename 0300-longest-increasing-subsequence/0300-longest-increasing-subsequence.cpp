// #include <print>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> lis;

        for (const auto& num: nums){
            // println("num: {}", num);

            if (lis.empty() || lis.back() < num){
                lis.push_back(num);
                // for (const auto& n: lis){
                //     print("{} ", n);
                // }
                // print("\n");
                continue;
            }
            if (lis.back() == num || lis.front() == num) continue;

            int left = 0, right = lis.size() - 1, middle = -1;
            while (left < right){
                middle = left + (right - left)/2;

                // println("left: {}, right: {}, middle: {}, middleVal: {}", left, right, middle, lis[middle]);

                if (lis[middle] < num){
                    left = middle + 1;
                } else {
                    right = middle;
                }
            }
            // if (middle != -1){
                // println("left: {}, right: {}, middle: {}", left, right, middle);
            // }
            
            lis[left] = num;

            // for (const auto& n: lis){
            //     print("{} ", n);
            // }
            // print("\n");
        }

        // println("\nResult:");
        // for (const auto& n: lis){
        //     print("{} ", n);
        // }

        return lis.size();
    }
};