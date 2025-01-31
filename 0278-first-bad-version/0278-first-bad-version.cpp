// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
typedef long long ll;

class Solution {
public:
    int firstBadVersion(int n) {
        ll left = 1;
        ll right = n;
        ll middle = (right + left) / 2;

        while (right - left > 1){
            // 1 -> 1
            // 2 -> 1
            // 3 -> 2
            // 4 -> 2
            // 5 -> 3, right -> 4, left -> 2
            // Except for last loop, always have a value on the left of middle
            bool badMiddle = isBadVersion(middle);

            if (badMiddle){
                right = middle;
            } else {
                left = middle;
            }
            middle = (right + left) / 2;
        }

        if (isBadVersion(middle)){
            return middle;
        } else {
            return middle + 1;
        }
    }
};