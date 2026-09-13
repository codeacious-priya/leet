class Solution {
public:
    int solve(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){
        // base
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        int pick=0;
        if(prev==-1||nums[i]>nums[prev]){
            pick=1+solve(i+1,i,nums,dp);
        }
        int not_pick=solve(i+1,prev,nums,dp);

        return dp[i][prev+1]=max(pick,not_pick);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size()+10,vector<int>(nums.size()+10,-1));
        return solve(0,-1,nums,dp);
        
    }
};