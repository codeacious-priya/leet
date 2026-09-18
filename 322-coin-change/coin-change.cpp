class Solution {
public:
    int solve(vector<int>&coins,int amount,int i,vector<vector<int>>&dp){
        // base 
        if(amount==0) return 0;
        if(amount<0) return 1e7;
        if(i>=coins.size()) return 1e7;
        if(i>=coins.size()&& amount>0) return 1e7;

        if(dp[i][amount]!=-1) return dp[i][amount];

        int pick=1e7;
        int not_pick=solve(coins,amount,i+1,dp);
        if(coins[i]<=amount){
            pick=1+solve(coins,amount-coins[i],i,dp);
        }
      
        
        return dp[i][amount]=min(pick,not_pick);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
      //  sort(coins.rbegin(),coins.rend());
        // edge cases
        if(amount==0) return 0;
        if(n==1 && amount%coins[0]!=0) return -1;
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        
       
        int ans=solve(coins,amount,0,dp);
        return ans==1e7?-1:ans;
    }
};