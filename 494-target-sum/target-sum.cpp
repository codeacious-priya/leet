class Solution {
public:
    int solve(vector<int>&nums,int target,int sum,int i,vector<vector<int>>&dp){
        // base case
        int n=nums.size();
        if(sum==target && i==n) return 1;
        if(i>=n) return 0;
        if(sum!=0 && i>=n) return 0;

        if(dp[i][sum+1000]!=-1) return dp[i][sum+1000];

        int add=solve(nums,target,sum+nums[i],i+1,dp);
        int sub=solve(nums,target,sum-nums[i],i+1,dp);
        return dp[i][sum+1000]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(2005,-1));
        
        int ans =solve(nums,target,0,0,dp);
        return ans;
        
        
    }
};