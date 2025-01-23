#include <print>

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freqMap;
        for (const auto& c: t) freqMap[c]++;

        for (const auto& [c, count]: freqMap){
            println("Char: {}, count: {}", c, count);
        }

        int sSize = s.size();
        int tSize = t.size();
        int left = 0;
        int right = 0;
        int validChars = 0;

        unordered_map<char, int> windowFreq;
        int minLeft = 0;
        int minRight = sSize;

        println("sSize: {}, tSize: {}", sSize, tSize);

        while (right < sSize){
            println("\nl:{}, r:{}, minLeft: {}, minRight: {}, validChars: {}, windowFreq:", left, right, minLeft, minRight, validChars);

            for (const auto& [c, count]: windowFreq){
                println("Char: {}, count : {}", c, count);
            }

            if (freqMap.contains(s[right])){
                println("Right match: {}, r:{}", s[right], right);

                windowFreq[s[right]]++;
                validChars++;

                while (windowFreq[s[right]] > freqMap[s[right]]){
                    if (freqMap.contains(s[left])){
                        println("Removing excess char: {}", s[left]);

                        windowFreq[s[left]]--;
                        validChars--;
                    }
                    left++;
                }

                while (!freqMap.contains(s[left])){
                    println("Removing excess left char at index: {}", left);

                    left++;
                }

                println("Valid chars: {}, tSize: {}, should update range: {}", validChars, tSize, validChars == tSize);
                println("Old range: {}, current range: {}", minRight - minLeft, right - left);

                if (validChars == tSize && right - left < minRight - minLeft){
                    minRight = right;
                    minLeft = left;

                    println("New minRight: {}, minLeft: {}!", minRight, minLeft);
                    if (right - left == tSize - 1) return s.substr(minLeft, minRight - minLeft + 1);
                }
            }

             println("Should move left: {}, right - left: {}, minRight - minLeft: {}", right - left >= minRight - minLeft, right - left, minRight - minLeft);

            if (right - left >= minRight - minLeft){
                if (freqMap.contains(s[left])){
                    validChars--;
                    windowFreq[s[left]]--;
                }

                left++;
            }
            right++;
        }

        println("minR:{}, minL{}", minLeft, minRight);
        if (minLeft == 0 && minRight == sSize) return "";

        return s.substr(minLeft, minRight - minLeft + 1);
    }
};