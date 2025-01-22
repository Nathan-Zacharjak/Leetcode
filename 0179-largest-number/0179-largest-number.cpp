class Solution {
public:
    string largestNumber(vector<int>& nums) {
        bool containsNonZero = false;
        vector<string> numsStr;
        for (const auto& num: nums){
            numsStr.push_back(to_string(num));
            if (num != 0){
                containsNonZero = true;
            }
        }

        if (!containsNonZero){
            return "0";
        }

        sort(numsStr.begin(), numsStr.end(), [](string& str1, string& str2){
            string concat1 = str1 + str2;
            string concat2 = str2 + str1;
            for (int i = 0; i < concat1.size(); i++){
                if (concat1[i] != concat2[i]){
                    return concat1[i] > concat2[i];
                }
            }
            return true;
        });

        string result;
        for (const auto& numStr: numsStr){
            result += numStr;
        }
        return result;
    }
};