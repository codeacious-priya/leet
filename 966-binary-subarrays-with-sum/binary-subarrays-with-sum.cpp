class Solution {
public:
    int solve(vector<int>&nums,int k){
        if(k<0) return 0;
        int n=nums.size();
        int cnt=0;
        int i=0;
        int sum=0;

        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>k){
                sum=sum-nums[i];
                i++;
            }
            cnt+=j-i+1;
            
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums,goal)-solve(nums,goal-1);
        
    }
};