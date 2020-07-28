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
int sh(vector<int>& arr, int strt, int end, int value) 
{ 
    int i; 
    for (i = strt; i <= end; i++) { 
        if (arr[i] == value) 
            break; 
    } 
    return i; 
} 
TreeNode* buildUtil(vector<int>& in, vector<int>& post, int inStrt,int inEnd, int* pIndex) 
{ 
    // Base case 
    if (inStrt > inEnd) 
        return NULL; 
  
    /* Pick current node from Postorder traversal using 
       postIndex and decrement postIndex */
    TreeNode* node = new TreeNode(post[*pIndex]); 
    (*pIndex)--; 
  
    /* If this node has no children then return */
    if (inStrt == inEnd) 
        return node; 
  
    /* Else find the index of this node in Inorder 
       traversal */
    int iIndex = sh(in, inStrt, inEnd, node->val); 
  
    /* Using index in Inorder traversal, construct left and 
       right subtress */
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex); 
  
    return node; 
} 

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int pIndex = n - 1; 
        return buildUtil(inorder, postorder, 0, n - 1, &pIndex); 
    }
};