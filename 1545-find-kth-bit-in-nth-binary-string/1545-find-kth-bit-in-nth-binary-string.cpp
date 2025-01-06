class Solution {
public:
    char findKthBit(int n, int k) {
        // Start with the largest string 2^n - 1 , and halve it while k > 1 (base case)
        // Keep track of the number of inversions done to the number before returning it
        int size = (1 << n) - 1;
        int invertCount = 0;

        while (k > 1) {
            // If k is in the middle, return the number, and flip if needed
            if (k == size/2 + 1){
                return invertCount % 2 == 0 ? '1' : '0';
            }

            // If k is in the first half, do nothing since the problem space will be halved
            // If k is in the 2nd half, reverse k's position in the first half, and flip shouldInvert
            if (k > size / 2){
                k = size + 1 - k;
                invertCount++;
            }

            // Look in the first half of the number
            size /= 2;
        }

        // If K is based off of the initial '0', then return based on shouldInvert
        return invertCount % 2 == 0 ? '0' : '1';
    }
};