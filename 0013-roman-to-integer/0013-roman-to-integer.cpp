class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map<char, int> costs = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        char lastLetter = '\0';
        unordered_map<char, pair<char, char>> subCases = {{'I', {'V', 'X'}}, {'X', {'L', 'C'}}, {'C', {'D', 'M'}}};

        for (const auto& c: s){
            result += costs[c];

            if (subCases.contains(lastLetter) && (c == subCases[lastLetter].first || c == subCases[lastLetter].second)){
                result -= costs[lastLetter] * 2;
            }

            lastLetter = c;
        }

        return result;
    }
};