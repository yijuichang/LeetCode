//404. Sum of Left Leaves
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
    int result = 0;
    void leftLeaves(TreeNode* root, bool from_left){
        if (!root) return;
        if (!root->left && !root->right && from_left){
            result += root->val;
        }
        if(root->left) leftLeaves(root->left, true);
        if(root->right) leftLeaves(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        leftLeaves(root, false);
        return result;
    }
};
/*
Runtime: 4 ms, faster than 83.75% of C++ online submissions for Sum of Left Leaves.
Memory Usage: 13.5 MB, less than 64.71% of C++ online submissions for Sum of Left Leaves.
*/
