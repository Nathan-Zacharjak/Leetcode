#include <array>

class Solution {
public:
    vector<int> findEvenNumbers(const vector<int>& digits) {
        // Create a digit bank holding the frequencies of each digit from the given array
        std::array<int,10> digitBank{0};
        for (const auto &digit : digits) digitBank.at(digit)++;

        std::vector<int> solutions{};

        std::array<int,10> solutionBank;
        // For every possible solution,
        for (int num = 100; num < 1000; num+=2){
            // Create a frequency count of each digit in the possible solution
            solutionBank.fill(0);
            int solutionDigits = num;

            while (solutionDigits != 0){
                int digit = solutionDigits % 10;
                solutionBank.at(digit)++;
                solutionDigits /= 10;
            }

            // Check there are enough digits in the given array for the possible solution
            bool isSolution = true;
            for (int i = 0; i < 10; i++){
                if (solutionBank.at(i) > digitBank.at(i)){
                    isSolution = false;
                    break;
                }
            }

            // Append the solution if valid
            if (isSolution){
                solutions.push_back(num);
            }
        }

        return solutions;
    }
};