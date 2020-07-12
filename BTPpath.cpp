//257. Binary Tree Paths
//Note: 這題找path 所以path function的 input 沒辦法用 pass by reference, 用pass by value 才不會互相干擾
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
    vector<string> result;
    void path(TreeNode* root, string p){
        if (!root) return;
        p.append(to_string(root->val));
        if (!root->left && !root->right){ 
            result.emplace_back(p);
        } 
        if(root->left){
            p.append("->");
            path(root->left,p);           
        }  
        if(root->right){
            if(!root->left) p.append("->");
            path(root->right,p);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string p;
        path(root,p);
        return result;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Paths.
Memory Usage: 13.7 MB, less than 66.89% of C++ online submissions for Binary Tree Paths.
*/
