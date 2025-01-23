class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> value = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int last = s.size() - 1;
        int total = value[last];

        for (int i = last; i >= 0; i--){
            if (value[s[i]] < value[s[i + 1]]){
                total -= value[s[i]];
            } else {
                total += value[s[i]];
            }
        }

        return total;
    }
};