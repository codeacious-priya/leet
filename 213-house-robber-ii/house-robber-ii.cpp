class Solution {
public:
    int solve(vector<int>&nums,int i,int start,vector<int>&dp){
        int n=nums.size();
        if(i<start) return 0;
        if(i==start) return nums[i];

        if(dp[i]!=-1) return dp[i];
        
        int pick=nums[i]+solve(nums,i-2,start,dp);
        int not_pick=solve(nums,i-1,start,dp);

        return dp[i]= max(pick,not_pick);

    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        vector<int>dp1(n,-1);
        int case1=solve(nums,n-2,0,dp1);

        vector<int>dp2(n,-1);
        int case2=solve(nums,n-1,1,dp2);

        return max(case1,case2);
        
        
    }
};