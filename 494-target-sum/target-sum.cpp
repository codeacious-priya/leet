class Solution {
public:
   int solve(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
    //. 
    if(i==0){
        if(target==0 && nums[0]==0){
            return 2;
        }
         if(target==0|| nums[0]==target){
            return 1;
        }
        
            return 0;
        
    }
    if(dp[i][target]!=-1){
        return dp[i][target];
    }
    int pick=0;
    if(nums[i]<=target){
        pick=solve(i-1,target-nums[i],nums,dp);
    }

    int not_pick=solve(i-1,target,nums,dp);

    return dp[i][target]=pick+not_pick;
   }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(auto it:nums){
            sum+=it;
        }
        if((sum-target)%2!=0||(sum-target)<0){
            return 0;
        }
        int n=nums.size();
        int t=(sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(t+1,-1));
        return solve(n-1,t,nums,dp);
    }
};