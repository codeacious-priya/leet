class Solution {
public:
    void solve(vector<int>&arr,int sum,int i,int target,vector<vector<int>>&ans,vector<int>&res){
    
        int n=arr.size();
        // base case
        if(sum==target){
            ans.push_back(res);
            return;
        }
        if(i==n || sum>target){
            return ;
        }

        //take 
         res.push_back(arr[i]);
        solve(arr,sum+arr[i],i,target,ans,res);
      
        // not take
        res.pop_back();
        solve(arr,sum,i+1,target,ans,res);



    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int sum=0;
        int i=0;
        vector<int>res;
        solve(candidates,sum,i,target,ans,res);
        return ans;
        
    }
};