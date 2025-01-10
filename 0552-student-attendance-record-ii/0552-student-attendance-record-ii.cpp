class Solution {
private:
    const int MOD = 1000000007;
    vector<vector<vector<int>>> dpArray;

    int RecordsCount(int charsLeft, int absentCount, int consecutiveLates) {
        if (absentCount == 2 || consecutiveLates == 3){
            return 0;
        }
        
        if (charsLeft == 0) {
            return 1;
        }

        if (dpArray[charsLeft][absentCount][consecutiveLates] != -1) {
            return dpArray[charsLeft][absentCount][consecutiveLates];
        }

        long long count = 0;

        // Choosing A
        count += RecordsCount(charsLeft - 1, absentCount + 1, 0) % MOD;
        // Choosing L
        count += RecordsCount(charsLeft - 1, absentCount, consecutiveLates + 1) % MOD;
        // Choosing P
        count += RecordsCount(charsLeft - 1, absentCount, 0) % MOD;

        return dpArray[charsLeft][absentCount][consecutiveLates] = count % MOD;
    }

public:
    int checkRecord(int n) {
        // memset(dpArray, -1, sizeof(dpArray));
        dpArray = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3, -1)));

        // // A:
        // // dpArray[n] = {{3,3,2},
        // //               {2,2,1}};
        // // dpArray[n][0] = {3,3,2};
        // // dpArray[n][1] = {2,2,1};
        // dpArray[n][0][0] = 3;
        // dpArray[n][0][1] = 3;
        // dpArray[n][0][2] = 2;

        // dpArray[n][1][0] = 2;
        // dpArray[n][1][1] = 2;
        // dpArray[n][1][2] = 1;
        // // Transition: sum of all next allowed character's choices
        // // Base Case: When you have a string of size 1, the number of choices
        // // are as above depending on the values of wasAbsent & consecutiveLates as
        // // indexes

        // // Index
        // for (int index = n - 1; index >= 0; index--) {
        //     for (int wasAbsent = 0; wasAbsent < 2; wasAbsent++) {
        //         for (int consecutiveLates = 0; consecutiveLates < 3; consecutiveLates++) {
        //             string allowedChars = "P";

        //             if (!wasAbsent) {
        //                 allowedChars.push_back('A');
        //             }
        //             if (consecutiveLates < 2) {
        //                 allowedChars.push_back('L');
        //             }

        //             ll count = 0;

        //             for (const auto& nextChar : allowedChars) {
        //                 count +=
        //                     dpArray[index + 1][wasAbsent || nextChar == 'A']
        //                            [nextChar == 'L' ? consecutiveLates + 1 : 0];
        //             }

        //             dpArray[index][wasAbsent][consecutiveLates] = count;
        //         }
        //     }
        // }

        // int result = 0;
        // for (int i = 0; i < 2; i++) {
        //     for (int j = 0; j < 3; j++) {
        //         print("{} ", dpArray[0][i][j]);
        //         result += dpArray[0][i][j];
        //     }
        //     print("\n");
        // }

        // return result;

        return RecordsCount(n, 0, 0);
    }
};