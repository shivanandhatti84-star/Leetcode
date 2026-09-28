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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> que;
        que.push(root);
        bool ltr=true;
        while(!que.empty()){
            int n=que.size();
            vector<int> list(n);
            for(int i=0;i<n;i++){
                auto temp=que.front();
                que.pop();
                if(ltr) list[i]=temp->val;
                else list[n-i-1]=temp->val;
                if(temp->left!=NULL) que.push(temp->left);
                if(temp->right!=NULL) que.push(temp->right);
            }
            ans.push_back(list);
            ltr=!ltr;
        }
        return ans;
    }
};