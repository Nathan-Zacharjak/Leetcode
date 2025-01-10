class Solution {
public:
    int checkRecord(int n) {
        const int MOD = 1000000007;
        vector<vector<int>> currDPState = vector<vector<int>>(2, vector<int>(3, 0));
        vector<vector<int>> nextDPState = vector<vector<int>>(2, vector<int>(3, 0));
        currDPState[0][0] = 1;

        for (int len = 0; len < n; len++){
            for (int absentCount = 0; absentCount <= 1; absentCount++){
                for (int consecutiveLates = 0; consecutiveLates <= 2; consecutiveLates++){
                    // Choosing A
                    if (absentCount < 1){
                        nextDPState[absentCount + 1][0] = (nextDPState[absentCount + 1][0] + currDPState[absentCount][consecutiveLates]) % MOD;
                    }
                    // Choosing L
                    if (consecutiveLates < 2){
                        nextDPState[absentCount][consecutiveLates + 1] = (nextDPState[absentCount][consecutiveLates + 1] + currDPState[absentCount][consecutiveLates]) % MOD;
                    }
                    // Choosing P
                    nextDPState[absentCount][0] = (nextDPState[absentCount][0] + currDPState[absentCount][consecutiveLates]) % MOD;
                }
            }

            currDPState = nextDPState;
            // Reset the next DP state to 0!
            nextDPState = vector<vector<int>>(2, vector<int>(3, 0));
        }

        int result = 0;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 3; j++){
                result = (result + currDPState[i][j]) % MOD;
            }
        }

        return result;
    }
};