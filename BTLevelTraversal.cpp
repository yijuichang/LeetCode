//107. Binary Tree Level Order Traversal II
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
    queue<TreeNode*> q;
    TreeNode* Node;
    vector<vector<int>> result;
    vector<int> one_level;
    int level_size;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        if(!root) return result;
        q.emplace(root);
        while (!q.empty()){
            level_size = q.size();
            for (int i = 0; i < level_size; ++i){
                Node = q.front();
                one_level.emplace_back(Node->val);
                if (Node->left) q.emplace(Node->left);
                if (Node->right) q.emplace(Node->right);
                q.pop();
            }
            result.emplace_back(one_level);
            one_level.clear();
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};
/*
Runtime: 8 ms, faster than 65.67% of C++ online submissions for Binary Tree Level Order Traversal II.
Memory Usage: 12.8 MB, less than 58.20% of C++ online submissions for Binary Tree Level Order Traversal II.
*/
