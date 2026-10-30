class Solution {
public:
    bool isSafe(int row ,int col,vector<string>&board,int n){
        int duprow=row;
        int dupcol=col;
     //up left
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        col=dupcol;
        row=duprow;
//straigt left
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        col=dupcol;
        row=duprow;
        //down left
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
    return true;
    }
    void solve(int col,vector<string>&board,vector<vector<string>>&ans,int n){
        //bc
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int row =0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q'; // do
                solve(col+1,board,ans,n);
                board[row][col]='.'; // undo
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        ///for loop ->jisse 1 col k haar row me Q put karke ,check karenge recursion se ki sari queen rakh sakte h recurssion se .if so usse vector me push ,else see new approach 

        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));

        solve(0,board,ans,n);
        return ans;

        
    }
};