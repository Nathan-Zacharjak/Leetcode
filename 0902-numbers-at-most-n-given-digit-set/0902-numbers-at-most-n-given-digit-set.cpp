class Solution {
private:
    int dpArray[10][2][2];

    int DigitDP(const string &digits, const string &max, int index, bool tight, bool hasLeadingZeros, const int &digitsSize){
        if (index == max.size()){
            return hasLeadingZeros ? 0 : 1;
        }

        if (dpArray[index][tight][hasLeadingZeros] != -1){
            return dpArray[index][tight][hasLeadingZeros];
        }

        char maxDigit = tight ? max.at(index) : '9';
        int firstDigitIndex = hasLeadingZeros ? 0 : 1;
        int count = 0;

        for (int i = firstDigitIndex; i < digitsSize; i++){
            char nextDigit = digits.at(i);

            if (nextDigit > maxDigit){
                break;
            }

            count += DigitDP(digits, max, index + 1, tight && nextDigit == maxDigit, nextDigit == '0', digitsSize);
        }

        dpArray[index][tight][hasLeadingZeros] = count;
        return count;
    }

public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string n_string = to_string(n);
        string digits_string = "0";

        for (const auto &digit : digits){
            digits_string.push_back(digit.at(0));
        }

        int digitsSize = digits_string.size();

        memset(dpArray, -1, sizeof(dpArray));
        return DigitDP(digits_string, n_string, 0, true, true, digitsSize);
    }
};