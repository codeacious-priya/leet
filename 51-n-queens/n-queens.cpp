class Solution {
public:
    bool issafe(int col,int row,int n,vector<vector<string>>&ans,vector<string>&res){
        int i=row;
        int j=col;

        while(col>=0){
           if(res[row][col]=='Q'){
            return false;
           }
           col--;

        }
        row=i;
        col=j;

         while(row>=0 && col>=0){
           if(res[row][col]=='Q'){
            return false;
           }
           row--;
           col--;

        }
        row=i;
        col=j;
        while(row<n&&col>=0){
            if(res[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }
        return true;
    }
    void solve(int col,int n,vector<vector<string>>&ans,vector<string>&res){
        // base case
        if(col==n){
            ans.push_back(res);
            return;

        }
       
        for(int row=0;row<n;row++){
            if(issafe(col,row,n,ans,res)){
                res[row][col]='Q';
                solve(col+1,n,ans,res);
                res[row][col]='.';

            }
            

        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>res(n,string (n,'.'));
        solve(0,n,ans,res);
        return ans;
        
    }
};