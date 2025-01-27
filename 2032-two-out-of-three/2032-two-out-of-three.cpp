class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_set<int> nums;
        unordered_map<int, int> numCount1;
        unordered_map<int, int> numCount2;
        unordered_map<int, int> numCount3;
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size3 = nums3.size();
        int maxSize = max(size1, max(size2, size3));

        for (int i = 0; i < maxSize; i++){
            if (i < size1){
                numCount1[nums1[i]]++;
                nums.insert(nums1[i]);
            }
            if (i < size2){
                numCount2[nums2[i]]++;
                nums.insert(nums2[i]);
            }
            if (i < size3){
                numCount3[nums3[i]]++;
                nums.insert(nums3[i]);
            }
        }

        vector<int> answer;

        for (const auto& num: nums){
            int count = 0;
            if (numCount1.contains(num)){
                count++;
            }
            if (numCount2.contains(num)){
                count++;
            }
            if (numCount3.contains(num)){
                count++;
            }

            if (count >= 2){
                answer.push_back(num);
            }
        }

        return answer;
    }
};