class Solution {
public:
   int solve(int i,long long prev,vector<int>&nums,vector<vector<long long>>&dp){
    // base case
    if(i<0){
        return 0;
    }
    if(dp[i][prev+1]!=-1){
        return dp[i][prev+1];
    }
    long long pick=0;
    long long not_pick=solve(i-1,prev,nums,dp);
    if(prev==-1 || nums[i]<nums[prev]){
        pick=1+solve(i-1,i,nums,dp);
    }
   

    return dp[i][prev+1]=max(pick,not_pick);
   }


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        
        long long  prev=-1;
        vector<vector<long long >>dp(n+1,vector<long long>(n+1,-1));
        return solve(n-1,prev,nums,dp);
        
    }
};