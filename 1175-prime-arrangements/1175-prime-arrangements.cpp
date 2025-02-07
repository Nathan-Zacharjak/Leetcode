class Solution {
public:
    int numPrimeArrangements(int n) {
        const long long MOD = 1e9 + 7;
        vector<bool> primes(n + 1, true);

        for (int p = 2; p * p <= n; p++){
            if (!primes[p]) continue;
            
            // Mark all multiples of the prime, up to n,
            // numbers before the square of the prime are already marked!
            for (int i = p * p; i <= n; i += p) primes[i] = false;
        }

        int primeCount = 0;
        for (int i = 2; i <= n; i++){
            if (primes[i]) primeCount++;
        }

        int nonPrimeCount = n - primeCount;
        int maxCount = max(primeCount, nonPrimeCount);
        long long permutations = 1;
        
        for (int i = 2; i <= maxCount; i++){
            if (i <= primeCount){
                permutations *= i;
                permutations %= MOD;
            }
            if (i <= nonPrimeCount){
                permutations *= i;
                permutations %= MOD;
            }
        }

        return permutations;
    }
};