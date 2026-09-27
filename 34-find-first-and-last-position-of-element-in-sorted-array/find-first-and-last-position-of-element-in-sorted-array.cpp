class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans={-1,-1};

        int n=nums.size();
        auto first=lower_bound(nums.begin(),nums.end(),target);
        auto second=lower_bound(nums.begin(),nums.end(),target+1);
        if(first==second){
            return ans;
        }
        ans[0]=first-nums.begin();
        ans[1]=second-nums.begin()-1;

        return ans;
        
    }
};