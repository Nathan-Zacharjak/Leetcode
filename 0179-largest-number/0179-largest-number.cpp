#include <print>

class Solution {
private:
    random_device rd;
    mt19937 gen;

    bool shouldGoBeforePivot(const int& num, const int& pivot){
        return to_string(num) + to_string(pivot) > to_string(pivot) + to_string(num);
    }

    int partition(vector<int>& nums, const int& start, const int& end){
        // choose a uniformly random pivot (from start to end)
        uniform_int_distribution<> dist(start, end);
        int pivot = dist(gen);
        println("start: {}, end: {}, pivot: {}", start, end, pivot);

        // partition nums so all numbers that make bigger numbers when on the left of pivot are left of the pivot,
        // and all nums that make bigger numbers on the right of the pivot are on the right
        int pivotNum = nums[pivot];
        // Shove pivot onto the end of the partition,
        swap(nums[end], nums[pivot]);
        // Save the last index containing a smaller number than pivot
        int firstBiggerNumIndex = start;
        
        // Loop except for the last value in partition, which is the pivot
        for (int i = start; i < end; i++){
            // If a number should go before the pivot, then shove it into the next low index and increment it
            if (shouldGoBeforePivot(nums[i], pivotNum)){
                swap(nums[firstBiggerNumIndex], nums[i]);
                firstBiggerNumIndex++;
            }
        }
        // Now, firstBiggerNumIndex will be pointing at the first largest number, and the pivot will be at the end
        // So we just have to swap these 2 numbers, and the pivot is in the right place!
        // (The pivot was swapped to the right at the start and is still there!)
        swap(nums[firstBiggerNumIndex], nums[end]);
        return firstBiggerNumIndex;
        
    }

    void quickSort(vector<int>& nums, const int& start, const int& end){
        // if start and end are equal or have crossed each other, return, parition is sorted! (1 or 0 element array is sorted)
        if (start >= end){
            return;
        }

        // partition nums so all numbers that make bigger numbers when on the left of pivot are left of the pivot,
        // and all nums that make bigger numbers on the right of the pivot are on the right
        int pivot = partition(nums, start, end);
        
        // Call quickSort on the 2 partitions
        quickSort(nums, start, pivot - 1);
        quickSort(nums, pivot + 1, end);
    }

public:
    string largestNumber(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);

        string result;
        for (const auto& num: nums) result += to_string(num);
        return result[0] == '0' ? "0" : result;
    }

    Solution(){
        mt19937 gen = mt19937(rd());
    }
};

// string largestNumber(vector<int>& nums) {
//     vector<string> numsStr;
//     bool containsNonZero = false;
//     for (const auto& num: nums){
//         numsStr.push_back(to_string(num));
//         if (num != 0){
//             containsNonZero = true;
//         }
//     }
//     if (!containsNonZero) return "0";
//     sort(numsStr.begin(), numsStr.end(), [](string& a, string& b){ return a + b > b + a;});
//     string result;
//     for (const auto& numStr: numsStr) result += numStr;
//     return result;
// }