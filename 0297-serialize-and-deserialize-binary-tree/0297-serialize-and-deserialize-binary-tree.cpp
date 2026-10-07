/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string str="";
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            auto temp=que.front();
            que.pop();
            if(temp==NULL) str+="!,";
            else str+=to_string(temp->val)+=',';
            if(temp!=NULL){
                que.push(temp->left);
                que.push(temp->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str="";
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            auto temp=que.front();
            que.pop();
            getline(s,str,',');
            if(str=="!"){
                temp->left=NULL;
            }
            else{
                temp->left=new TreeNode(stoi(str));
                que.push(temp->left);
            }
            getline(s,str,',');
            if(str=="!"){
                temp->right=NULL;
            }
            else{
                temp->right=new TreeNode(stoi(str));
                que.push(temp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));