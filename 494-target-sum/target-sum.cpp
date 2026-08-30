class Solution {
public:
    int solve(int i,int target,vector<int>&nums,vector<unordered_map<int,int>>&dp){
        // 
        if(i<0){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[i].count(target)){
            return dp[i][target];
        }

        int add=solve(i-1,target-nums[i],nums,dp);
        int sub=solve(i-1,target+nums[i],nums,dp);

        return dp[i][target]=add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<unordered_map<int,int>>dp(n);
        return solve(n-1,target,nums,dp);
        
    }
};