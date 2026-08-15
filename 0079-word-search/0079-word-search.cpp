class Solution {
public:
    bool fun(vector<vector<char>> &board,string &word,int i,int j,int ind){
        if(ind==word.length()){
            return true;
        }
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) return false;
        if(board[i][j]!=word[ind]) return false;
        char temp=board[i][j];
        board[i][j]='.';
        bool found=fun(board,word,i+1,j,ind+1)||fun(board,word,i-1,j,ind+1)||fun(board,word,i,j+1,ind+1)||fun(board,word,i,j-1,ind+1);
        board[i][j]=temp;
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if (fun(board, word, i, j, 0))
                    return true;

                }
            }
        }
        return false;
    }
};