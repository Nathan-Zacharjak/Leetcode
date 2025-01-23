class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int i = 0;
        int size = s.size();

        unordered_map<string, int> costs = {{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000},
                                            {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

        while (i < size){
            if (i < size - 1 && costs.contains(s.substr(i, 2))){
                result += costs[s.substr(i, 2)];
                i++;
            } else {
                result += costs[s.substr(i, 1)];
            }
            i++;
        }

        return result;
    }
};