class Solution {
public:
    void solve(int k,int target,int i,vector<int>&arr,vector<vector<int>>&ans,vector<int>&res){
        
        //base case
        if(target==0 && k==0){
            ans.push_back(res);
            return;
        }
        if(k == 0 && target != 0){
            return;
        }
        if(i==arr.size()){
            return;
        }
        
        if(target<0){
            return;
        }
        
        //take 
       
        res.push_back(arr[i]);
        solve(k-1,target-arr[i],i+1,arr,ans,res);
         res.pop_back();
         
        //not take
       
        solve(k,target,i+1,arr,ans,res);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        vector<vector<int>>ans;
        vector<int>res;

        solve(k,n,0,arr,ans,res);
        return ans;
        
    }
};