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
    int index=0;
    TreeNode* build(unordered_map<int,int> &mapl,vector<int> &inorder,vector<int> &preorder,int start,int end){
        if(start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[index]);
        int i=mapl[preorder[index++]];
        root->left=build(mapl,inorder,preorder,start,i-1);
        root->right=build(mapl,inorder,preorder,i+1,end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mapl;
        for(int i=0;i<inorder.size();i++){
            mapl[inorder[i]]=i;
        }
        return build(mapl,inorder,preorder,0,inorder.size()-1);
    }
};