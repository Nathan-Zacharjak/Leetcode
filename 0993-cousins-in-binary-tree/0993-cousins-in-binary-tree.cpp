// #include <print>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    bool traverseTree(TreeNode* node, const int& x, const int& y, TreeNode* parent, int& xDepth, int& yDepth, int& xParent, int& yParent, const int& depth){      
        if (xDepth != -1 && yDepth != -1){
            return xDepth == yDepth && xParent != yParent;
        }
        if (node == nullptr){
            return false;
        }

        // println("node: {}, x: {}, y: {}, xDepth: {}, yDepth: {}, xParent: {}, yParent: {}, depth: {}", node->val, x, y, xDepth, yDepth, xParent, yParent, depth);

        // if (parent == nullptr){
        //     println("null parent");
        // } else {
        //     println("parent: {}", parent->val);
        // }


        if (node->val == x){
            xDepth = depth;
            xParent = parent == nullptr ? -1: parent->val;
        } else if (node->val == y){
            yDepth = depth;
            yParent = parent == nullptr ? -1: parent->val;
        }

        if (traverseTree(node->left, x, y, node, xDepth, yDepth, xParent, yParent, depth + 1) || traverseTree(node->right, x, y, node, xDepth, yDepth, xParent, yParent, depth + 1)){
            return true;
        } else {
            return false;
        }
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = -1;
        int yDepth = -1;
        int xParent = -1;
        int yParent = -1;
        int depth = 0;

        return traverseTree(root, x, y, nullptr, xDepth, yDepth, xParent, yParent, depth);
    }
};