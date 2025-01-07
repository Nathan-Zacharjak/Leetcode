class Solution {
private:
    int nextNum(int n){
        int sum = 0;

        while (n != 0){
            int digit = n % 10;
            n /= 10;
            sum += digit * digit;
        }

        return sum;
    }

public:
    bool isHappy(int n) {
        int slowNum = n;
        int fastNum = nextNum(n);

        while (fastNum != 1 && slowNum != fastNum){
            slowNum = nextNum(slowNum);
            fastNum = nextNum(nextNum(fastNum));
        }

        return fastNum == 1;
    }
};