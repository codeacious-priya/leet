class Solution {
public:
   
   int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp){
    // base case
    int m=grid.size();
    int n=grid[0].size();
    if(i==m-1 && j==n-1){
        return grid[i][j];
    }
    if(i>=m||j>=n){
        return INT_MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int down=solve(i+1,j,grid,dp);
    int right=solve(i,j+1,grid,dp);
    
    return dp[i][j]=grid[i][j]+ min(down,right);
   }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>dp(grid.size()+1,vector<int>(grid[0].size(),-1));
        return solve(0,0,grid,dp);

        
    }
};