class Solution {
public:
    int solve(int i,int amount,vector<int>&coin,vector<vector<int>>&dp){
        // 
        if(i==0){
            return amount%coin[0]==0;
        }
        if(dp[i][amount]!=-1){
            return dp[i][amount];
        }

        int not_pick=solve(i-1,amount,coin,dp);
        int pick=0;
        if(coin[i]<=amount){
            pick=solve(i,amount-coin[i],coin,dp);
        }
        return dp[i][amount]=pick+not_pick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));

        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0)
            dp[0][t]=1;
            
                
            
        }

        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
            unsigned   long long not_pick=dp[i-1][t];
              unsigned  long long pick=0;
                if(coins[i]<=t){
                    pick=dp[i][t-coins[i]];
                }
                dp[i][t]=pick+not_pick;
            }
        }
        return (int)dp[n-1][amount];
    }
};