//538. Convert BST to Greater Tree
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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        queue<TreeNode*> q,q1; 
        //q records the node of the tree through BFS
        //At the each node in q,  q1 is utilized to record the nodes with greater value. Complexity is O(log(N))
        queue<int> add;
        //" add " records the amount of sum that we want to add 
        
        TreeNode* current_node, * check_tree_node;
        q.emplace(root);
        int sum;
        while (!q.empty()){
            sum = 0;   
            current_node =q.front();
            q1.emplace(root);
            while (!q1.empty()){
                check_tree_node = q1.front();
                if (current_node->val >= check_tree_node->val){
                  if (check_tree_node->right) q1.emplace(check_tree_node->right);  
                }
                else{
                    sum += check_tree_node->val;
                    if (check_tree_node->left) q1.emplace(check_tree_node->left); 
                    if (check_tree_node->right) q1.emplace(check_tree_node->right);  
                }
                q1.pop();
            }
            
            add.emplace(sum);
            if (current_node->left) q.emplace(current_node->left);
            if (current_node->right) q.emplace(current_node->right) ;
            q.pop();
        }
        
        q.emplace(root);
        while (!q.empty()){
            current_node =q.front();
            current_node->val += add.front();
            if (current_node->left) q.emplace(current_node->left);
            if (current_node->right) q.emplace(current_node->right);
            q.pop();
            add.pop();
        }
        
        return root;
    }
};
