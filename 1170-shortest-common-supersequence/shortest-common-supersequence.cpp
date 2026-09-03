class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.size();
        int m=str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }

        }
        
        
        int len=m+n-dp[n][m];
        string s(len,'$');
       
        int idx=len-1;
        int i=n,j=m;

        while(i>0 && j>0){
            if(str1[i-1]==str2[j-1]){
                s[idx]=str1[i-1];
                idx--;
                i--;
                j--;
            }
            else if( dp[i-1][j]>dp[i][j-1]){
                s[idx]=str1[i-1];
                idx--;
                i--;
            }
            else {
                s[idx]=str2[j-1];
                idx--;
                j--;
            }
        }
        while(i>0){
            s[idx]=str1[i-1];
            i--;
            idx--;
        }
        while(j>0){
            s[idx]=str2[j-1];
            j--;
            idx--;
        }
       
        return s;
    }
};