class Solution {
public:
    bool solve(int i,vector<int>&arr,vector<bool>&vis){
        // bc
        int n= arr.size();
        if(i<0 || i>n-1)return false;
        if(vis[i])return false;
        if(arr[i]==0) return true;
        bool left=0,right=0;
        if(!vis[i]){
            vis[i]=1;
            left= solve(i+arr[i],arr,vis);
            right=solve(i-arr[i],arr,vis);
        }
       
        return (left || right);
    }
    bool canReach(vector<int>& arr, int start) {
        int n=arr.size();
        vector<bool>vis(n,0);
        return solve(start,arr,vis);
        
    }
};