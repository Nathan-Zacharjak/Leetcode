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
public:
    // Checks whether the left or right side of the tree is balanced
    bool isValidBST(TreeNode* root, TreeNode* minNode = nullptr, TreeNode* maxNode = nullptr){
        // Traverse the root of the new tree, and make sure all nodes on that side of the tree are balanced
        // Once you hit a leaf node, mark it as balanced
        if (root == nullptr) return true;
        if (minNode != nullptr && root->val <= minNode->val) return false;
        if (maxNode != nullptr && root->val >= maxNode->val) return false;

        // If the root is reached and passes the balance check, the tree is balanced
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};