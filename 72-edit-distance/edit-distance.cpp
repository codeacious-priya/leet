class Solution {
public:
    int solve(int i,int j,string s,string w,vector<vector<int>>&dp){
        // base case
        if(i<0) return j+1;
        if(j<0) return i+1;
        int ans=1e7;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==w[j]){
            ans=solve(i-1,j-1,s,w,dp);
        }

        int insert=1+solve(i-1,j,s,w,dp);
        int del=1+solve(i,j-1,s,w,dp);
        int replace=1+solve(i-1,j-1,s,w,dp);

        return dp[i][j]=min({insert,del,replace,ans});
    }
    int minDistance(string word1, string word2) {
        int m=word1.size();
        int n=word2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

        return solve(m-1,n-1,word1,word2,dp);
        
    }
};