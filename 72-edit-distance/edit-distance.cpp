class Solution {
public:
   
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

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
        return dp[n][m];
    }
};