class Solution {
public: 
    bool solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        // base case
        if(target==0){
            return true;
        }
        int n=nums.size();
        if(i>=n){
            return false;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int pick=0;
        if(nums[i]<=target){
            pick=solve(i+1,target-nums[i],nums,dp);
        }
        int not_pick=solve(i+1,target,nums,dp);

        return dp[i][target]=pick||not_pick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];

        }
        if(sum%2==1){
            return false;
        }
        vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
        return solve(0,sum/2,nums,dp);
        
    }
};