class Solution {
public:
    void solve(vector<int>&arr,int i,int sum,int target,vector<vector<int>>&ans,vector<int>&res){
        // base case
        
        int n=arr.size();
        if(sum==target){
            ans.push_back(res);
            return;
        }
        if(sum>target || i==n){
            return;
        }
        
        
        // take
        res.push_back(arr[i]);
        solve(arr,i+1,sum+arr[i],target,ans,res);

        //not_take
        res.pop_back();
        if(i+1<n ){
            while( i+1<n && arr[i]==arr[i+1]){
            i++;
        }
        solve(arr,i+1,sum,target,ans,res);
        }
        
        else{
            solve(arr,i+1,sum,target,ans,res);
        }
  

        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        solve(candidates,0,0,target,ans,res);
        return ans;
        
    }
};