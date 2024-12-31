#include <print>

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        // Get a topological sort, and adjaceny list of the graph
        vector<unordered_set<int>> adjList(n);
        // Find all nodes with no incoming edges
        vector<int> incomingEdgeCount(n, 0);

        // Count the number of incoming edges for each edge
        for (const auto &edge : edges){
            int parent = edge.at(0);
            int child = edge.at(1);
            incomingEdgeCount.at(child)++;
            adjList.at(parent).insert(child);
        }

        // Make a queue with the nodes with no incoming edges inserted first
        queue<int> nodeQ{};
        for (int node = 0; node < n; node++){
            if (incomingEdgeCount.at(node) == 0){
                nodeQ.push(node);
            }
        }

        vector<int> topoSort{};

        // Do a while loop until the queue is empty,
        while (!nodeQ.empty()){
            // Pop off the next node
            int node = nodeQ.front();
            nodeQ.pop();

            // Add it to the topological sort
            topoSort.push_back(node);

            for (const auto &child : adjList.at(node)){
                // Remove all of its edges from the graph (decrease the incoming edge counts of each child by 1)
                incomingEdgeCount.at(child)--;

                // If any children reach a count of 0 incoming edges, push it to the queue
                if (incomingEdgeCount.at(child) == 0){
                    nodeQ.push(child);
                }
            }
        // Pop the next node...
        }

        println("Topological sort:");
        for (const auto &node : topoSort){
            println("{}", node);
        }

        // Use the topological sort to process each node in the correct order
        // to pass all ancestors to child nodes correctly
        vector<unordered_set<int>> ancestorSets(n);

        // Loop through all nodes in topological order,
        for (const auto &parent : topoSort){
            // and add all of the node's ancestors to the node's children
            for (const auto &child : adjList.at(parent)){
                for (const auto &ancestor : ancestorSets.at(parent)){
                    ancestorSets.at(child).insert(ancestor);
                }

                // and add the node itself as an ancestor to each child
                ancestorSets.at(child).insert(parent);
            }
        }

        for (int i = 0; i < n; i++){
            println("{}'s ancestors:", i);
            for (const auto &ancestor : ancestorSets.at(i)){
                println("{}", ancestor);
            }
        }

        // Convert the array of sets into an array of arrays using the node index order
        vector<vector<int>> ancestorLists(n);
        for (int node = 0; node < n; node++){
            for (int ancestor = 0; ancestor < n; ancestor++){
                if (ancestor != node && ancestorSets.at(node).contains(ancestor)){
                    ancestorLists.at(node).push_back(ancestor);
                }
            }
        }

        // Return the array of ancestors
        return ancestorLists;
    }
};