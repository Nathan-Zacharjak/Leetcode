#include <print>

class Solution {
private:
    int getOperationsCount1(const string& s){
        int zeroAtIndex0Operations = 0;
        int oneAtIndex0Operations = 0;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '0' && i % 2 == 0){
                oneAtIndex0Operations++;
            } else if (s[i] == '1' && i % 2 == 0){
                zeroAtIndex0Operations++;
            } else if (s[i] == '0' && i % 2 == 1){
                zeroAtIndex0Operations++;
            } else if (s[i] == '1' && i % 2 == 1){
                oneAtIndex0Operations++;
            }
        }

        return min(zeroAtIndex0Operations, oneAtIndex0Operations);
    }

    int getOperationsCount(const string& s, const int& maxIdenticalLength){
        if (maxIdenticalLength == 1) return getOperationsCount1(s);

        int operations = 0;
        int groupSize = 1;
        char groupChar = s[0];

        for (int i = 1; i < s.size(); i++){
            if (groupChar == s[i]){
                groupSize++;
            } else {
                operations += groupSize / (maxIdenticalLength + 1);
                groupSize = 1;
                groupChar = s[i];
            }
        }

        operations += groupSize / (maxIdenticalLength + 1);

        return operations;
    }

    int findMaxGroup(const string& s){
        int currentGroup = 1;
        int maxGroup = 1;
        char currentChar = s[0];
        for (int i = 1; i < s.size(); i++){
            if (currentChar == s[i]){
                currentGroup++;
            } else {
                if (maxGroup < currentGroup){
                    maxGroup = currentGroup;
                }
                currentGroup = 1;
                currentChar = s[i];
            }
        }
        if (maxGroup < currentGroup){
            maxGroup = currentGroup;
        }
        return maxGroup;
    }

public:
    int minLength(string s, int numOps) {
        if (numOps == 0) return findMaxGroup(s);

        int n = s.size();
        int left = 1;
        int right = n;
        int potentialAnswer = -1;

        while (left <= right){
            int guessOfMinIdenticalLength = left + (right - left)/2;
            println("guessOfMinIdenticalLength: {}", guessOfMinIdenticalLength);
            int operationsCount = getOperationsCount(s, guessOfMinIdenticalLength);
            println("Opscount: {}", operationsCount);

            if (operationsCount > numOps){
                left = guessOfMinIdenticalLength + 1;
            } else {
                right = guessOfMinIdenticalLength - 1;
                potentialAnswer = guessOfMinIdenticalLength;
            }
        }

        return potentialAnswer;
    }
};