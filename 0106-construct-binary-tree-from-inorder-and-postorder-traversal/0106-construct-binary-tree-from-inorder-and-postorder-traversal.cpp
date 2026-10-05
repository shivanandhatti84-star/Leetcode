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
    
    TreeNode* build(unordered_map<int,int> &mapl,vector<int> &inorder,vector<int> &postorder,int start,int end,int &index){
        if(start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[index]);
        int i=mapl[postorder[index--]];
        root->right=build(mapl,inorder,postorder,i+1,end,index);
        root->left=build(mapl,inorder,postorder,start,i-1,index);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mapl;
        for(int i=0;i<inorder.size();i++){
            mapl[inorder[i]]=i;
        }
        int index = postorder.size() - 1;
        return build(mapl,inorder,postorder,0,inorder.size()-1,index);
    }
};