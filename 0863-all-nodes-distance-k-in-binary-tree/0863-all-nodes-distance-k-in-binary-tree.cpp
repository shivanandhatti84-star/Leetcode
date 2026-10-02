/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void fun(vector<int> &ans,TreeNode* target,int k,unordered_map<TreeNode*,TreeNode*> &mapl,unordered_set<TreeNode*> &visited){
        if(!target||visited.count(target)){
            return;
        }
        visited.insert(target);
        if(k==0){
            ans.push_back(target->val);
            return;
        }
        fun(ans,mapl[target],k-1,mapl,visited);
        fun(ans,target->left,k-1,mapl,visited);
        fun(ans,target->right,k-1,mapl,visited);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> que;
        unordered_map<TreeNode*,TreeNode*> mapl;
        que.push(root);
        while(!que.empty()){
            auto temp=que.front();
            que.pop();
            if(temp->right){
                mapl[temp->right]=temp;
                que.push(temp->right);
            }
            if(temp->left){
                mapl[temp->left]=temp;
                que.push(temp->left);
            }
        }
        unordered_set<TreeNode*> visited;
        fun(ans,target,k,mapl,visited);
        return ans;
    }
};