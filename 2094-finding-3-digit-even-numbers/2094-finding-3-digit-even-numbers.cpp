#include <set>

class Solution {
public:
    vector<int> findEvenNumbers(const vector<int>& digits) {
        std::set<int> digitSet{};

        // For every even digit,
        for (int i = 0; i < digits.size(); i++){
            if (digits[i] % 2 != 0){
                continue;
            }
            int num = digits[i];

            // For every digit that isn't the even one,
            for (int j = 0; j < digits.size(); j++){
                if (i == j){
                    continue;
                }
                num += digits[j] * 10;

                // For every digit that isn't the even or first one,
                for (int k = 0; k < digits.size(); k++){
                    int thirdNum = digits[k];

                    if (thirdNum == 0 || i == k || j == k){
                        continue;
                    }

                    // Add the 3 digits to a set
                    digitSet.insert(num + thirdNum * 100);
                }

                num -= digits[j] * 10;
            }
        }

        // Cast the set to a vector
        std::vector<int> digitVector(digitSet.begin(), digitSet.end());
        // Return the vector
        return digitVector;
    }
};