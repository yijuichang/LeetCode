//993. Cousins in Binary Tree
//用 BFS 找 depth 和 parent
//紀錄 parent 時 多用了一個queue 可能可以不用?

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
    bool find_x;
    bool find_y;
    queue<TreeNode*> q;
    queue<int> parent;
    TreeNode* Node;
    int level_size, parent_x, parent_y;
    bool isCousins(TreeNode* root, int x, int y) {        
        //use BFS to find depth and parent of the targeting values x,y
        q.emplace(root);
        parent.emplace(0);
        while (!q.empty()){
            level_size = q.size();
            find_x = false;
            find_y = false;
            for (int i = 0; i < level_size; ++i){
                Node = q.front();
                if (x == Node->val){
                    find_x = true;
                    parent_x = parent.front();
                } 
                if (y == Node->val){
                    find_y = true;
                    parent_y = parent.front();
                } 
                if (Node->left){
                    parent.emplace(Node->val);
                    q.emplace(Node->left);
                } 
                if (Node->right){
                    parent.emplace(Node->val);
                    q.emplace(Node->right);
                } 
                q.pop();
                parent.pop();
            }
            if ((find_x && find_y) && parent_x != parent_y) return true;
        }        
        return false;     
    }
};
/*
Runtime: 4 ms, faster than 79.98% of C++ online submissions for Cousins in Binary Tree.
Memory Usage: 11.4 MB, less than 17.39% of C++ online submissions for Cousins in Binary Tree.
*/
