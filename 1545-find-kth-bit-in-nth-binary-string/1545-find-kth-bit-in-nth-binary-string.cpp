class Solution {
public:
    char findKthBit(int n, int k) {
        // Recursive pattern: look at each half of the number as a simulation
        // If the number is in the first index, it is 0
        if (n == 1){
            return '0';
        }
        // Next dertermine the number's size by bit shifting 1 left, n times, equal to 2^n or n doublings, which each layer does
        int size = 1 << n;
        int middle = size/2;
        // If the number is in the middle index, it is 1
        if (k == middle){
            return '1';
        }
        // If the number is in the first half, then recursely reduce the problem to just that part of the string
        if (k < middle){
            return findKthBit(n-1, k);
        }
        // If the number is in the second half, then recursively reduce the problem to just the first half of the string,
        if (k > middle){
            // but then invert the number
            // and take into account the string being reversed, so look from the end of the first half
            char flippedBit = findKthBit(n-1, size - k) == '1' ? '0' : '1';
            return flippedBit;
        }
        return '0';
    }
};