#include <print>

class Solution {
private:
    int binarySearchW(const vector<int>& heights, int target){
        int left = 0;
        int right = heights.size() - 1;
        int firstSameOrSmallerThanIndex = heights.size();
        // Because all of those heights to the right are larger than or on top of the point's height

        while (left <= right){
            int middle = left + (right - left)/2;

            if (heights[middle] >= target){
                firstSameOrSmallerThanIndex = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return firstSameOrSmallerThanIndex;
    }

public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<int> answer;

        vector<vector<int>> hToW(101, vector<int>());

        for (const auto& rec: rectangles){
            hToW.at(rec[1]).push_back(rec[0]);
        }

        for (int i = 1; i <= 100; i++){
            sort(hToW.at(i).begin(), hToW.at(i).end());
        }

        for (int i = 1; i <= 5; i++){
            println("\nHeight: {}, widths:", i);
            for (const auto& width: hToW.at(i)){
                print("{} ", width);
            }
        }

        for (const auto& point: points){
            int x = point[0];
            int y = point[1];
            int count = 0;

            for (int height = y; height <= 100; height++){
                if (!hToW[height].empty()){
                    count += hToW[height].size() - binarySearchW(hToW[height], x);
                }
            }

            answer.push_back(count);
        }

        return answer;
    }
};