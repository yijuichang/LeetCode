//235. Lowest Common Ancestor of a Binary Search Tree
//這題不用那麼複雜 key point 是找到 一個node 其值剛好在pq中間 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    vector<TreeNode*> intervals;
    bool des;
    void inorderTra(TreeNode* root, const int &a, const int &b){
        if(root->left) inorderTra(root->left,a,b);
        if(root->val >= a && root->val <= b) intervals.emplace_back(root);
        if(root->right) inorderTra(root->right,a,b);
        return;
    }
    void find_des(TreeNode* root, const int &b ){
        if (root->left) find_des(root->left,b);
        if (root->val == b) des = true;
        if (root->right) find_des(root->right,b);
        return;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a,b;
        a = min(p->val,q->val);
        b = max(p->val,q->val);
        inorderTra(root,a,b);
        for(auto interval : intervals){
            des = false;
            find_des(interval,b);
            if (des) return interval;
        }
        return nullptr;
    }
};



/*
a=min(p,q)
b=max(p,q)

Inorder travelsal to find all node between [a,b]

loop (find desendant)

*/

/* better solution 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

      if(p->val<root->val && q->val<root->val)
      {
        return lowestCommonAncestor(root->left,p,q);
      }
      if(p->val>root->val && q->val>root->val)
      {
        return lowestCommonAncestor(root->right,p,q);
      }
      return root;
    }
};

*/


/*
Runtime: 48 ms, faster than 30.99% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
Memory Usage: 23.6 MB, less than 5.28% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
*/
