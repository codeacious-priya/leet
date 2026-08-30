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
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(n-1,amount,coins,dp);
        
    }
};