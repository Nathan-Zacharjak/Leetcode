class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> inOutDegree;

        for (const auto& pair: pairs){
            adjList[pair[0]].push_back(pair[1]);
            inOutDegree[pair[0]]++;
            inOutDegree[pair[1]]--;
        }

        int startNode = pairs[0][0];
        for (const auto& [node, degree]: inOutDegree){
            if (degree == 1){
                startNode = node;
                break;
            }
        }

        vector<int> path;
        stack<int> nodeStack;
        nodeStack.push(startNode);

        while (!nodeStack.empty()){
            auto& edges = adjList[nodeStack.top()];

            if (edges.empty()){
                path.push_back(nodeStack.top());;
                nodeStack.pop();
            } else {
                nodeStack.push(edges.back());
                edges.pop_back();
            }
        }

        int maxPathIndex = path.size() - 1;
        vector<vector<int>> answer;
        answer.reserve(maxPathIndex);

        for (auto i = maxPathIndex; i > 0; i--){
            answer.push_back({path[i], path[i - 1]});
        }

        return answer;
    }
};