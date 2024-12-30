class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        // Continue until the current number is 0
        while (n > 0){
            // Find the last digit in base K, by finding the remainder of n divide k
            sum += n % k;
            // Find the next largest digits by diviing by K
            n /= k;
        }
        return sum;
    }
};