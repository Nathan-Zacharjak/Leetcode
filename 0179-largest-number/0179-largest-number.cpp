class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsStr;
        bool containsNonZero = false;
        for (const auto& num: nums){
            numsStr.push_back(to_string(num));
            if (num != 0){
                containsNonZero = true;
            }
        }

        if (!containsNonZero) return "0";

        sort(numsStr.begin(), numsStr.end(), [](string& a, string& b){ return a + b > b + a;});

        string result;
        for (const auto& numStr: numsStr) result += numStr;

        return result;
    }
};