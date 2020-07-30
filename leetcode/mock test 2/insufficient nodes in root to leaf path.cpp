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

int ss(TreeNode* root, int limit, int curr){
    if(root == NULL) return curr;
    
    int leftval = ss(root->left,limit,curr+root->val);
    int rightval = ss(root->right,limit,curr+root->val);
    int mx = 0;
    if (root->left == NULL) mx = rightval;
    else if (root->right == NULL) mx = leftval;
        else if (leftval>rightval) mx = leftval;
            else mx = rightval;
    
    if (leftval<limit) root->left = NULL;
    if (rightval<limit) root->right = NULL;
    
    return mx;
        
}
class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int mx = ss(root,limit,0);
        if (mx<limit) return NULL;
        return root;
    }
};