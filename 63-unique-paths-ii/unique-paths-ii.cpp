class Solution {
public:
int m,n;
    int solve(int i,int j,vector<vector<int>>& arr,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m ||j>=n){
            return 0;
        }
        if(dp[i][j]!=0){
            return dp[i][j];
        }
     
       
        int down=0,right=0;
        if(i+1<m && arr[i+1][j]!=1){
            down=solve(i+1,j,arr,dp);
            

        }
        if(j+1<n && arr[i][j+1]!=1)
        right=solve(i,j+1,arr,dp);
        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         m=obstacleGrid.size();
         n=obstacleGrid[0].size();
         vector<vector<int>>dp(m,vector<int>(n,0));
         if(obstacleGrid[0][0]==1) return 0;
        return solve(0,0,obstacleGrid,dp);
        
    }
};