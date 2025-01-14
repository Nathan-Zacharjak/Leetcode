#include <print>

class Solution {
private:
    double dist(const vector<int> &p1, const vector<int> &p2){
        int xDist = p1[0] - p2[0];
        int yDist = p1[1] - p2[1];

        return (xDist * xDist) + (yDist * yDist);
    }

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // A collapsed square with all points into one point is not a square:
        if (p1 == p2 && p2 == p3 && p3 == p4){
            return false;
        }

        array<vector<int>, 4> points = {p1, p2, p3, p4};

        sort(points.begin(), points.end(), [](const vector<int> &p1, const vector<int> &p2){
            return p1[0] == p2[0] ? p1[1] < p2[1] : p1[0] < p2[0];
        });

        // 3 cases: 
        // Side distances
        bool equalWidth = dist(points[0], points[1]) == dist(points[2], points[3]);
        bool equalHeight = dist(points[0], points[2]) == dist(points[1], points[3]);
        bool equalLength = dist(points[0], points[1]) == dist(points[0], points[2]);

        // Diagonal distances
        bool equalDiagonals = dist(points[0], points[3]) == dist(points[1], points[2]);

        return equalWidth && equalHeight && equalDiagonals && equalLength;
    }
};