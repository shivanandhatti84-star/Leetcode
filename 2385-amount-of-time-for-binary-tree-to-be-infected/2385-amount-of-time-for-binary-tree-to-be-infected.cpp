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
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;
        int time=0;
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* targetNode = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr->val == start) {
                targetNode = curr;
            }
            if (curr->left) {
                parentMap[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parentMap[curr->right] = curr;
                q.push(curr->right);
            }
        }
        
        if (!targetNode) return 0; 
        queue<TreeNode*> que;
        unordered_set<TreeNode*> visited;
        que.push(targetNode);
        visited.insert(targetNode);
        while(!que.empty()){
            
            int size=que.size();
            bool flag=false;
            for(int i=0;i<size;i++){
                auto temp=que.front();
                que.pop();
                if(temp->left&&!visited.count(temp->left)){
                    flag=true;
                    visited.insert(temp->left);
                    que.push(temp->left);
                }
                  if (temp->right && !visited.count(temp->right)) {
                    flag = true;
                    visited.insert(temp->right);
                    que.push(temp->right);
                }
                if (parentMap.count(temp) && !visited.count(parentMap[temp])) {
                    flag = true;
                    visited.insert(parentMap[temp]);
                    que.push(parentMap[temp]);
                }
            }
            if(flag) time++;

        }
        return time;
    }
};