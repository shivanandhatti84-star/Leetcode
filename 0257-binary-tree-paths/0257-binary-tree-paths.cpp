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
    void fun(vector<string> &ans,TreeNode* root,vector<int> &a){
        if(root==NULL){
           
            return;
        }
        a.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr){
                
                string result = "";
                for (int i = 0; i < a.size(); i++) {
                    result += to_string(a[i]);
                    if(i!=a.size()-1) result+="->";
                }
            ans.push_back(result);
        }
        else{
            fun(ans,root->left,a);
            fun(ans,root->right,a);
        }
        a.pop_back();
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        vector<int> a;
       
        fun(ans,root,a);
        return ans;
    }
};