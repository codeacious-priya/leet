class Solution {
public:
    int solve(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        // base case
        //deletion->to ""
        //insert->s2
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
           return dp[i][j]= solve(i-1,j-1,s1,s2,dp);
        }
        else{
            int insert=1+solve(i-1,j,s1,s2,dp);
            int del=1+solve(i,j-1,s1,s2,dp);
            int rep=1+solve(i-1,j-1,s1,s2,dp);
            return dp[i][j]= min({insert,del,rep});   
        }
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    return solve(n-1,m-1,word1,word2,dp);
    /*
       vector<vector<long long>>dp(n+1,vector<long long>(m+1,0));
       // delete
       for(int i=1;i<=n;i++){
        dp[i][0]=i;
       }
       //insert
       for(int j=1;j<=m;j++){
        dp[0][j]=j;
       }
       
       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                int del=1+dp[i-1][j];
                int insert=1+dp[i][j-1];
                int replace=1+dp[i-1][j-1];

                dp[i][j]=min({del,insert,replace});
            }
        }
       }
        return dp[n][m];*/
    }
};