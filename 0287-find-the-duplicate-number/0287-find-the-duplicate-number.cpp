class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortise = nums[0];
        int hare = nums[0];

        do {
            tortise = nums[tortise];
            hare = nums[nums[hare]];
        } while (tortise != hare);

        tortise = nums[0];

        while (tortise != hare){
            tortise = nums[tortise];
            hare = nums[hare];
        }

        return hare;
    }
};