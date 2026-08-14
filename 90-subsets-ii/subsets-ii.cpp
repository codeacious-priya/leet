class Solution {
public:
    void solve(vector<int>&nums,int i,vector<int>&res,vector<vector<int>>&ans){
        // base case
        int n=nums.size();
        if(i==n){
            ans.push_back(res);
            return;
        }

        //take 
        res.push_back(nums[i]);
        solve(nums,i+1,res,ans);
        res.pop_back();
        if(i+1<n ){
              while(i+1<n && nums[i]==nums[i+1]){
            i++;

        }
        }

        // not take
        solve(nums,i+1,res,ans);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>res;
        sort(nums.begin(),nums.end());

        solve(nums,0,res,ans);
        return ans;
        
    }
};