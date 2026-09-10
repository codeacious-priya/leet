class Solution {
public:
    int solve(int i,vector<int>&nums,vector<int>&dp){
        // bc
        if(i>=nums.size()){
             return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        int pick=nums[i]+solve(i+2,nums,dp);
        int not_pick=solve(i+1,nums,dp);
        return dp[i]=max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
       return solve(0,nums,dp);
        
    }
};