class Solution {
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

        for (const auto& point: points){
            int x = point[0];
            int y = point[1];
            int count = 0;

            for (int height = y; height <= 100; height++){
                if (!hToW[height].empty()){
                    count += hToW[height].end() - lower_bound(hToW[height].begin(), hToW[height].end(), x);
                }
            }

            answer.push_back(count);
        }

        return answer;
    }
};