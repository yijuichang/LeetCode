//530. Minimum Absolute Difference in BST
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
    int pre = -1;
    int min = INT_MAX;
    void inorderTraversal(TreeNode* root, int &min){
        if (root->left) inorderTraversal(root->left, min);
        if ((root->val - pre < min) && (pre != -1)) min = root->val - pre;
        pre = root->val;
        if (root->right) inorderTraversal(root->right, min);
    }
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root, min);
        return min;
    }
};
/*
Runtime: 36 ms, faster than 31.26% of C++ online submissions for Minimum Absolute Difference in BST.
Memory Usage: 25.1 MB, less than 97.20% of C++ online submissions for Minimum Absolute Difference in BST.
*/
