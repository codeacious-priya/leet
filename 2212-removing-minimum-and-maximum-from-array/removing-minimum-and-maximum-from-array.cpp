class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int maxi=-1e9;
        int mae=0;
        int mie=n-1;
        int mini=1e9;
        if(n==1) return 1;

        for(int i=0;i<n;i++){
            if(mini>nums[i]){
                mini=nums[i];
                mie=i;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                mae=i;
            }
        }
       int r=max(mie,mae);
       int l=min(mie,mae);

       return min({r+1,n-l,l+1+n-r});
    }
};