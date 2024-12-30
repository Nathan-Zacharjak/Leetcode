#include <map>

class Solution {
public:
    vector<int> findEvenNumbers(const vector<int>& digits) {
        std::map<int, int> digitBank{};

        for (int i = 0; i < 10; i++){
            digitBank.insert({i, 0});
        }

        for (const auto &digit : digits){
            digitBank.at(digit) += 1;
        }


        std::vector<int> result{};

        for (int i = 1; i < 10; i++){
            if (digitBank.at(i) <= 0){
                continue;
            }
            digitBank.at(i)--;

            int firstNum = i * 100;

            for (int j = 0; j < 10; j++){
                if (digitBank.at(j) <= 0){
                    continue;
                }
                digitBank.at(j)--;

                int sum = firstNum + j * 10;

                for (int k = 0; k < 10; k+=2){
                    if (digitBank.at(k) <= 0){
                        continue;
                    }

                    result.push_back(sum + k);
                }

                digitBank.at(j)++;
            }

            digitBank.at(i)++;
        }

        return result;
    }
};