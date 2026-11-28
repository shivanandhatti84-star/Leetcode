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
        vector<vector<int>> arr;
        if(!root) return arr;
        queue<TreeNode*> que;
        bool lfr=1;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int> a(size);
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();
                que.pop();
                int idx=lfr?i:size-i-1;
                a[idx]=node->val;
                if (node->left)que.push(node->left);
                if (node->right)que.push(node->right);
            }
            arr.push_back(a);
            lfr=!lfr;
        }
        return arr;
    }
};