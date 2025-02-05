class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int left = 0;
        int right = 0;
        int nonGrumpyCount = 0;
        int windowCount = 0;
        int maxWindowCount = 0;
        int n = customers.size();

        while (right < n){
            if (right - left >= minutes){
                windowCount -= customers[left];
                left++;
            }

            if (grumpy[right] == 0){
                nonGrumpyCount += customers[right];
                customers[right] = 0;
            } else {
                windowCount += customers[right];
                maxWindowCount = max(maxWindowCount, windowCount);
            }
            
            right++;
        }

        return maxWindowCount + nonGrumpyCount;
    }
};