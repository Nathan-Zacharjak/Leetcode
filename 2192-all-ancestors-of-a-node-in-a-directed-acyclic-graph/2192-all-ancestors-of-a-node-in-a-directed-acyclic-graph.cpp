class Solution {
private:
    void DFS(const int node, unordered_set<int> &visited, const vector<vector<int>> &parents, int n){
        // In the DFS,
        // Flag the node as "visited" in a hash table
        visited.insert(node);

        // For each of the node's parents,
        for (const auto &parent : parents.at(node)){
            // If the current parent is not visited,
            if (!visited.contains(parent)){
                // DFS down the node's parents
                DFS(parent, visited, parents, n);
            }
        }
    };

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Create a parent vector of vectors for every node in the graph
        vector<vector<int>> parents(n);
        for (const auto &edge : edges){
            int parent = edge.at(0);
            int child = edge.at(1);
            parents.at(child).push_back(parent);
        }

        vector<vector<int>> ancestors(n);
        // For every node,
        for (int node = 0; node < n; node++){
            // Create a hash table for the visitied nodes in DFS
            unordered_set<int> visited{};
            // DFS down the node
            DFS(node, visited, parents, n);
            // For every node,
            for (int i = 0; i < n; i++){
                // If the node is flagged, and is not the starting node, add the node to the starting node's vector
                if (visited.contains(i) && i != node){
                    ancestors.at(node).push_back(i);
                }
            }
        }

        // Return the ancestors array
        return ancestors;
    }
};