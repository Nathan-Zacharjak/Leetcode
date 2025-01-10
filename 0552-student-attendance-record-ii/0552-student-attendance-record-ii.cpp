// #include <print>

typedef long long ll;

class Solution {
private:
    const int MOD = 1000000007;
    // vector<vector<vector<ll>>> dpArray;
    vector<vector<ll>> currDPState = vector<vector<ll>>(2, vector<ll>(3, 0));
    vector<vector<ll>> nextDPState = vector<vector<ll>>(2, vector<ll>(3, 0));

    // int RecordsCount(int len, int absentCount, int consecutiveLates) {
    //     if (absentCount == 2 || consecutiveLates == 3){
    //         return 0;
    //     }

    //     if (len == 0) {
    //         return 1;
    //     }

    //     if (dpArray[len][absentCount][consecutiveLates] != -1) {
    //         return dpArray[len][absentCount][consecutiveLates];
    //     }

    //     long long count = 0;

    //     // Choosing A
    //     count += RecordsCount(len - 1, absentCount + 1, 0) % MOD;
    //     // Choosing L
    //     count += RecordsCount(len - 1, absentCount, consecutiveLates + 1) % MOD;
    //     // Choosing P
    //     count += RecordsCount(len - 1, absentCount, 0) % MOD;

    //     return dpArray[len][absentCount][consecutiveLates] = count % MOD;
    // }

public:
    int checkRecord(int n) {
        // dpArray = vector<vector<vector<ll>>>(n + 1, vector<vector<ll>>(2, vector<ll>(3, 0)));
        // dpArray[0][0][0] = 1;
        currDPState[0][0] = 1;

        for (int len = 0; len < n; len++){
            // println("len: {}", len);

            // for (int i = 0; i < 2; i++){
            //     for (int j = 0; j < 3; j++){
            //         print("{}\t", currDPState[i][j]);
            //     }
            //     print("\n");
            // }

            for (int absentCount = 0; absentCount <= 1; absentCount++){
                for (int consecutiveLates = 0; consecutiveLates <= 2; consecutiveLates++){
                    // Choosing A
                    if (absentCount < 1){
                        // nextDPState[len + 1][absentCount + 1][0] += currDPState[len][absentCount][consecutiveLates] % MOD;
                        nextDPState[absentCount + 1][0] += currDPState[absentCount][consecutiveLates] % MOD;
                    }
                    // Choosing L
                    if (consecutiveLates < 2){
                        // nextDPState[len + 1][absentCount][consecutiveLates + 1] += currDPState[len][absentCount][consecutiveLates] % MOD;
                        nextDPState[absentCount][consecutiveLates + 1] += currDPState[absentCount][consecutiveLates] % MOD;
                    }
                    // Choosing P
                    // nextDPState[len + 1][absentCount][0] += currDPState[len][absentCount][consecutiveLates] % MOD;
                    nextDPState[absentCount][0] += currDPState[absentCount][consecutiveLates] % MOD;
                }
            }

            currDPState = nextDPState;
            // Reset the next DP state to 0!
            nextDPState = vector<vector<ll>>(2, vector<ll>(3, 0));
            // print("\n");
        }

        // println("len: {}", n);

        long long result = 0;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 3; j++){
                // print("{}\t", currDPState[i][j]);
                result += currDPState[i][j] % MOD;
            }
            // print("\n");
        }

        return result % MOD;

        // return RecordsCount(n, 0, 0);
    }
};