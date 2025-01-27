class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> bitMasks(101, 0);
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size3 = nums3.size();
        int maxSize = max(size1, max(size2, size3));

        for (int i = 0; i < maxSize; i++){
            if (i < size1){
                bitMasks[nums1[i]] |= 1 << 0;
            }
            if (i < size2){
                bitMasks[nums2[i]] |= 1 << 1;
            }
            if (i < size3){
                bitMasks[nums3[i]] |= 1 << 2;
            }
        }

        // 011 = 3, 101 = 5, 110 = 6, 111 = 7
        vector<int> answer;
        for (int i = 0; i < 101; i++){
            if (bitMasks[i] == 3 || bitMasks[i] >= 5){
                answer.push_back(i);
            }
        }

        return answer;
    }
};