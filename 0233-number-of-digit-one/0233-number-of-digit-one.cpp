// #include <print>

typedef long long ll;

class Solution {
private:
    int dpArray[10][2][10];
    // array<array<array<ll, 100000>, 2>, 9> dpArray;

    int DigitDP(string &max, short index, bool tight, int count){
        // println("Max: {}, Index: {}, Tight: {}, count: {}", max, index, tight, count);

        if (index == max.size()){
            return count;
        }

        if (dpArray[index][tight][count] != -1){
            return dpArray[index][tight][count];
        }

        int result = 0;

        char maxDigit = tight ? max.at(index) : '9';

        for (char nextDigit = '0'; nextDigit <= maxDigit; nextDigit++){
            int nextCount = nextDigit == '1' ? count + 1 : count;

            bool nextTight = tight && nextDigit == max.at(index);

            // println("Next Digit: {}", nextDigit);
            result += DigitDP(max, index + 1, nextTight, nextCount);
            // println("Returned from: {}, with count: {}", nextDigit, nextCount);
        }


        dpArray[index][tight][count] = result;
        return result;
    }

public:
    int countDigitOne(int n) {
        string max = to_string(n);

        memset(dpArray, -1, sizeof(dpArray));
        
        return DigitDP(max, 0, true, 0);
        // return 0;
    }
};