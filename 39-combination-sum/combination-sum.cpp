class Solution {
public:
    void solve(int i,vector<int>& candidates,int target,vector<vector<int>>&ans, vector<int>temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0){
            return;
        }
        if(i>=candidates.size()){
            return ;
        }
        if( candidates[i]<=target){
           temp.push_back(candidates[i]);
           solve(i,candidates,target-candidates[i],ans,temp);
           temp.pop_back();
        }
        
        solve(i+1,candidates,target,ans,temp);
        

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(0,candidates,target,ans,temp);
        return ans;
        
    }
};