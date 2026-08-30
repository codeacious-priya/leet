class Solution {
public:
    int solve(int i,int target,vector<int>&nums){
        // 
        if(i<0){
            if(target==0){
                return 1;
            }
            else{
                return 0;
            }
        }

        int add=solve(i-1,target-nums[i],nums);
        int sub=solve(i-1,target+nums[i],nums);

        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(n-1,target,nums);
        
    }
};