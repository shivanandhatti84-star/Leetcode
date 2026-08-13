class Solution {
public:
    bool sol(int row,int col,vector<string> &board,int n){
        int r=row;
        int c=col;
        while(col>=0 && row>=0){
            if(board[row][col]=='Q') return false;
            col--;
            row--;
        }
        col=c;
        row=r;
        while(col>=0){
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }
        col=c;
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        return true;
    }
    void fun(vector<string> &board,int col,vector<vector<string>> &arr,int n){
        if(col==n){
            arr.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(sol(row,col,board,n)){
                board[row][col]='Q';
                fun(board,col+1,arr,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> arr;
        vector<string> board(n, string(n, '.'));
        fun(board,0,arr,n);
        return arr;
    }
};