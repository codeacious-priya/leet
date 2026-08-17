class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int ans=0;
        for(int i=0;i<n;i++){
           ans^=nums[i];
            maxi=max(maxi,ans);
        }
        
        if(ans!=0){
            return n;
        }
        bool allzero=all_of(nums.begin(),nums.end(),[](int i){
            return i==0;});
        if(allzero) return 0;

        return n-1;
    }
};