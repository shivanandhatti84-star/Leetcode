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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> bsf;
        queue<TreeNode*> que;
        if(root==NULL) return bsf;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int> b;
            for(int i=0;i<size;i++){
                auto temp=que.front();
                que.pop();
                b.push_back(temp->val);
                if(temp->left!=NULL) que.push(temp->left);
                if(temp->right!=NULL) que.push(temp->right);
            }
            bsf.push_back(b);
        }
        return bsf;
    }
};