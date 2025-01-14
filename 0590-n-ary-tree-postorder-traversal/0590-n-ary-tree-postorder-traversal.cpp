/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void postOrderHelper(vector<int> &order, Node* node){
        for (const auto &child : node->children){
            postOrderHelper(order, child);
        }
        order.push_back(node->val);
    }

public:
    vector<int> postorder(Node* root) {
        vector<int> order;
        if (root != nullptr){
            postOrderHelper(order, root);
        }
        return order;
    }
};