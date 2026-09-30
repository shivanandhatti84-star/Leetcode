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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<pair<TreeNode*,int>> que;
        map<int,int> mapl;
        que.push({root,0});
        while(!que.empty()){
            auto temp=que.front();
            que.pop();
            mapl[temp.second]=temp.first->val;
            if(temp.first->left) que.push({temp.first->left,temp.second+1});
            if(temp.first->right) que.push({temp.first->right,temp.second+1});

        }
        for(auto it:mapl){
            ans.push_back(it.second);
        }
        return ans;
    }
};