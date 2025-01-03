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
        // // For every query
        // for (const auto query : queries){
        //     // Set the start and end positions of the query in the array
        //     int index = query.at(0);
        //     int end = query.at(1);
        //     // Sliding window check each element for parity in range
        //     while (index != end && nums.at(index) % 2 != nums.at(index + 1) % 2){
        //         index++;
        //     }
        //     // If non parity pair found, push false, break loop
        //     // Else push true
        //     answer.push_back(index == end);
        // }
        // Return bit vector
        return answer;
    }
};