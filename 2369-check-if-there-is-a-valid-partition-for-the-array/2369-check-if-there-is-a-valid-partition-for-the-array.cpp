// #include <print>

class Solution {
private:
    // Doesn't check if you're off the side in the next iteration, just the conditions of the first 3 values from start
    pair<bool, bool> is2or3SkipViable(const vector<int>& nums, const int& start){
        bool is2Equal = false;
        bool is3Equal = false;
        bool is3Increasing = false;

        if (nums.size() > start + 1 && nums[start] == nums[start + 1]){
            is2Equal = true;
        }
        if (nums.size() > start + 2 && nums[start] == nums[start + 1] && nums[start] == nums[start + 2]){
            is3Equal = true;
        }
        if (nums.size() > start + 2 && nums[start] == nums[start + 1] - 1 && nums[start + 1] == nums[start + 2] - 1){
            is3Increasing = true;
        }

        return {is2Equal, is3Equal || is3Increasing};
    }

    // bool DPHelper(const vector<int>& nums, const int& start, vector<int>& DPArray) {
    //     if (start == nums.size()) return true;

    //     if (DPArray[start] != -1) return DPArray[start];

    //     bool is2Equal = false;
    //     bool is3Equal = false;
    //     bool is3Increasing = false;

    //     if (nums.size() > start + 1 && nums[start] == nums[start + 1]){
    //         is2Equal = DPHelper(nums, start + 2, DPArray);
    //     }
    //     if (nums.size() > start + 2 && nums[start] == nums[start + 1] && nums[start] == nums[start + 2]){
    //         is3Equal = DPHelper(nums, start + 3, DPArray);
    //     }
    //     if (nums.size() > start + 2 && nums[start] == nums[start + 1] - 1 && nums[start + 1] == nums[start + 2] - 1){
    //         is3Increasing = DPHelper(nums, start + 3, DPArray);
    //     }

    //     return DPArray[start] = is2Equal || is3Equal || is3Increasing;
    // }

public:
    bool validPartition(const vector<int>& nums) {
        // vector<pair<bool, bool>> DPArray(nums.size(), {false, false});
        // DPArray[0] = is2or3SkipViable(nums, 0);
        pair<bool, bool> oneSkipPair = is2or3SkipViable(nums, 0);
        pair<bool, bool> twoSkipPair = {false, false};
        pair<bool, bool> threeSkipPair = {false, false};
        // int last2SkipIndex = -2;
        // int last3SkipIndex = -3;

        for (auto i = 1; i < nums.size(); i++){
            // DPArray[i] = is2or3SkipViable(nums, i);
            pair<bool, bool> viable = is2or3SkipViable(nums, i);

            // bool last2Skip = i - 2 < 0 ? false : DPArray[i - 2].first;
            bool last2Skip = twoSkipPair.first;
            // bool last3Skip = i - 3 < 0 ? false : DPArray[i - 3].second;
            bool last3Skip = threeSkipPair.second;

            if (!last2Skip && !last3Skip){
                // DPArray[i] = {false, false};
                viable = {false, false};
            }
            
            threeSkipPair = twoSkipPair;
            twoSkipPair = oneSkipPair;
            oneSkipPair = viable;
        }

        // println("DPArray:");
        // for (auto i = 0; i < DPArray.size(); i++){
        //     println("i: {}, 2skip: {}, 3skip: {}", i, DPArray[i].first, DPArray[i].second);
        // }

        // bool twoSkipViable = false;
        // int twoSkipIndex = DPArray.size() - 2;
        // bool threeSkipViable = false;
        // int threeSkipIndex = DPArray.size() - 3;

        // if (twoSkipIndex >= 0){
        //     twoSkipViable = DPArray[twoSkipIndex].first;
        // }
        // if (threeSkipIndex >= 0){
        //     threeSkipViable = DPArray[threeSkipIndex].second;
        // }

        // return twoSkipViable || threeSkipViable;

        return twoSkipPair.first || threeSkipPair.second;
    }
};