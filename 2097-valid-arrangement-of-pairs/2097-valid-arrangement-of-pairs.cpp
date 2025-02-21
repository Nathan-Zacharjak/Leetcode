// #include <print>

class Solution {
private:
    void DFS(vector<int>& DFSResult, unordered_map<int, unordered_set<int>>& adjListOut, const int& currentNode){
        // println("Visiting node: {}", currentNode);

        while (!adjListOut[currentNode].empty()){
            int nextNode = *(adjListOut[currentNode].begin());
            adjListOut[currentNode].erase(nextNode);

            DFS(DFSResult, adjListOut, nextNode);
        }

        DFSResult.push_back(currentNode);
    }

public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        vector<vector<int>> answer;
        unordered_map<int, unordered_set<int>> adjListOut;
        unordered_map<int, unordered_set<int>> adjListIn;

        for (auto i = 0; i < pairs.size(); i++){
            adjListOut[pairs[i][0]].insert(pairs[i][1]);
            adjListIn[pairs[i][1]].insert(pairs[i][0]);
        }

        // println("adjListOut:");
        // for (const auto& [node, edges]: adjListOut){
        //     println("node: {}", node);
        //     for (const auto& edge: edges){
        //         print("{} ", edge);
        //     }
        //     print("\n");
        // }
        // println("adjListIn:");
        // for (const auto& [node, edges]: adjListIn){
        //     println("node: {}", node);
        //     for (const auto& edge: edges){
        //         print("{} ", edge);
        //     }
        //     print("\n");
        // }

        bool outDegreeMatchesIn = true;
        int nodeWithOneMoreOutToIn = -1;

        for (const auto& [node, edges]: adjListOut){
            if (adjListOut[node].size() == adjListIn[node].size() + 1){
                outDegreeMatchesIn = false;
                nodeWithOneMoreOutToIn = node;
                break;
            }
        }

        if (outDegreeMatchesIn) nodeWithOneMoreOutToIn = pairs[0][0];
        // println("outDegreeMatchesIn: {}, nodeWithOneMoreOutToIn: {}", outDegreeMatchesIn, nodeWithOneMoreOutToIn);

        vector<int> DFSResult;
        DFS(DFSResult, adjListOut, nodeWithOneMoreOutToIn);
        reverse(DFSResult.begin(), DFSResult.end());

        // println("DFSResult:");
        // for (const auto& node: DFSResult){
        //     print("{} ", node);
        // }
        // print("\n");

        int lastNode = DFSResult[0];
        for (auto i = 1; i < DFSResult.size(); i++){
            int node = DFSResult[i];
            answer.push_back({lastNode, node});
            lastNode = node;
        }

        return answer;
    }
};