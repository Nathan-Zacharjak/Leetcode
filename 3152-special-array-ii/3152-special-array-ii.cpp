class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> answer{};
        vector<int> specialSetIndex{};
        specialSetIndex.push_back(0);

        for (int i = 1; i < nums.size(); i++){
            if (nums.at(i-1) % 2 == nums.at(i) % 2){
                specialSetIndex.push_back(specialSetIndex.at(i-1) + 1);
            } else {
                specialSetIndex.push_back(specialSetIndex.at(i-1));
            }
        }

        for (const auto &query : queries){
            int start = query.at(0);
            int end = query.at(1);

            answer.push_back(specialSetIndex.at(start) - specialSetIndex.at(end) == 0);
        }

        return answer;
    }
};