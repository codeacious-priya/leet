class Solution {
public: 
    int solve(int row,int col,vector<vector<int>>& arr,vector<vector<long long>>&dp){
        // base case
        int n=arr.size();
        
        for(int col=0;col<n;col++){
            dp[n-1][col]=arr[n-1][col];
        }
        for(int row=n-2;row>=0;row--){
            for(int col=row;col>=0;col--){
                int first=arr[row][col]+dp[row+1][col];
                int second=arr[row][col]+dp[row+1][col+1];

                dp[row][col]=min(first,second);
            }
        }
        

        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[0].size();
        vector<vector<long long>>dp(n+10,vector<long long>(n+10,-1));
        return solve(0,0,triangle,dp);
        
    }
};