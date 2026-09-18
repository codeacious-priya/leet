class Solution {
public:
    int solve(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        // 
        if(i==0){
            if(amount%coins[i]==0){
                return 1;
            }
            else{
                return 0;
            }

        }
        if(i<0) return 0;
        if(i<0 && amount!=0) return 0;

        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=0;
        if(coins[i]<=amount){
            pick=solve(i,amount-coins[i],coins,dp);
        }
        int not_pick=solve(i-1,amount,coins,dp);
        return dp[i][amount]=pick+not_pick;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+10,-1));
        return solve(n-1,amount,coins,dp);
        
    }
};