class Solution {
public:
    vector<int> divisibilityArray(const string& word, const int& m) {
        vector<int> answer;
        long long previousRemainder = 0;
        int zero = '0';
        long long divisionEnd = 0;

        for (auto i = 0; i < word.size(); i++){
            int digit = word[i] - zero;
            divisionEnd = (previousRemainder * 10) + digit;
            int remainder = divisionEnd % m;
            answer.push_back(remainder == 0);
            previousRemainder = remainder;
        }

        return answer;
    }
};