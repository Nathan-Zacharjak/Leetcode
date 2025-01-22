class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> numsStr;
        for (const auto& num: nums) numsStr.push_back(to_string(num));

        sort(numsStr.begin(), numsStr.end(), [](string& a, string& b){ return a + b > b + a;});
        if (numsStr[0] == "0") return "0";

        string result;
        for (const auto& numStr: numsStr) result += numStr;

        return result;
    }
};