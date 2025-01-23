class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int num = 0;
        int last = 0;
        
        for (int i = s.size() - 1; i >= 0; i--){
            switch(s[i]){
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
                default: num = 0; break;
            }
            total += num;
            if (last > num) total -= num * 2;
            last = num;
        }

        return total;
    }
};