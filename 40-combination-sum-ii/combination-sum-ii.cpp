class Solution {
public:

    void solve(int i,vector<int>& candidates,int target, vector<vector<int>>&ans,vector<int>temp){
         if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=candidates.size()){
            return;
        }
       
        if(target<0) return;
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],ans,temp);
            temp.pop_back();
        }
        while (i + 1 < candidates.size() &&
               candidates[i] == candidates[i + 1]) {
            i++;
        }

        solve(i+1,candidates,target,ans,temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());

        solve(0,candidates,target,ans,temp);
        return ans;
        
    }
};