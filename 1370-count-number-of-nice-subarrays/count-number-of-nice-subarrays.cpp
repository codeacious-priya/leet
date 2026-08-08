class Solution {
public:
    int solve(vector<int>&nums,int k){
        if(k<0) return 0;
        int i=0;
        long long ans=0;
        int cnt=0;
        int n=nums.size();

        for(int j=0;j<n;j++){
            if(nums[j]%2){
                cnt++;
            }
            while(cnt > k){
                if(nums[i]%2!=0)cnt--;
                i++;
            }
            ans += j-i+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};