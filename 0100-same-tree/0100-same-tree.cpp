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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> qp;
        queue<TreeNode*> qq;
        qp.push(p);
        qq.push(q);
        while(!qp.empty()&&!qq.empty()){
            if(qp.size()!=qq.size()) return false;
            int size=qq.size();
            for(int i=0;i<size;i++){
                auto x=qq.front();
                qq.pop();
                auto y=qp.front();
                qp.pop();
                if(!x&&!y) continue;
                if(!x||!y||x->val!=y->val) return false;
                
                qq.push(x->left);
                qq.push(x->right);
                qp.push(y->left);
                qp.push(y->right);


            }
        }
        if(!qq.empty()||!qp.empty()) return false;
        return true;

    }
};