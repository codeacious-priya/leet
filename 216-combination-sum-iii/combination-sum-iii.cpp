class Solution {
public:
    void solve(int i,int k,int target,int arr[],vector<vector<int>>&ans,vector<int>temp){
        if(target==0 && temp.size()==k ){
            ans.push_back(temp);
            return;
        }
        if(i>=9){
            return;
        }
        if(target<0) return;

        if(arr[i]<=target){
            temp.push_back(arr[i]);
            solve(i+1,k,target-arr[i],arr,ans,temp);
            temp.pop_back();
        }
        solve(i+1,k,target,arr,ans,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       int arr[9]={1,2,3,4,5,6,7,8,9};
       vector<vector<int>>ans;
       vector<int>temp;

       solve(0,k,n,arr,ans,temp);
       return ans;

        
    }
};