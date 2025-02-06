class Solution {
public:
    vector<string> sortPeople(vector<string>& names, const vector<int>& heights) {
        int n = names.size();
        priority_queue<pair<int, string>> nameQueue;

        for (auto i = 0; i < n; i++){
            nameQueue.push({heights[i], names[i]});
        }

        for (auto i = 0; i < n; i++){
            names[i] = nameQueue.top().second;
            nameQueue.pop();
        }

        return names;
    }
};