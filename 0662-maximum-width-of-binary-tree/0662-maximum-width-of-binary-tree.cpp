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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> que;
        que.push({root,0});
        while(!que.empty()){
            int mmin=que.front().second;
            int size=que.size();
            int first,last;
            for(int i=0;i<size;i++){
                long long cur=que.front().second-mmin;
                auto node=que.front().first;
                que.pop();
                if(i==0) first=cur;
                if(i==size-1) last=cur;
                if(node->left) que.push({node->left,2*cur+1});
                if(node->right) que.push({node->right,2*cur+2});
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};