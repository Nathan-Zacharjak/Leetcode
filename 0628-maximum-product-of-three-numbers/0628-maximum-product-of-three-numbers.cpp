#include <print>

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        deque<int> top3;
        int neg1 = 0;
        int neg2 = 0;

        for (const auto& num: nums){
            int front = top3.empty() ? -10000 : top3.front();

            if (num < 0){
                if (neg1 > num){
                    neg2 = neg1;
                    neg1 = num;
                } else if (neg2 > num){
                    neg2 = num;
                }
            }
            
            if (num > front || top3.size() < 3){
                if (top3.size() >= 3){
                    top3.pop_front();
                }
                top3.push_back(num);
                sort(top3.begin(), top3.end());
            }
            println("size: {}, num :{}, front: {}", top3.size(), num, top3.front());
        }

        long long productPos = 1;
        long long productNeg = neg1 * neg2;
        // If top 3 numbers are all negative
        if (top3.back() >= 0) {
            productNeg *= top3.back();
        } else {
            productNeg = -1e12;
        }
        
        while (!top3.empty()){
            productPos *= top3.front();
            top3.pop_front();
        }

        return max(productPos, productNeg);
    }
};