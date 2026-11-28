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
    int fun(TreeNode* root,int &maxl,int count){
        if(root==NULL) return 0;
        int lh=fun(root->left,maxl,count+1);
        int rh=fun(root->right,maxl,count+1);
        maxl=max(maxl,count);
        return max(lh,rh);
    }
    int maxDepth(TreeNode* root) {
        int maxl=0;
         fun(root,maxl,1);
         return maxl;
    }
};