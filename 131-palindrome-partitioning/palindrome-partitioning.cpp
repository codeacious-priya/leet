class Solution {
public:
    bool isPalindrome(int i,int j,string s){
        while(i<=j){
            if(s[i++]!=s[j--]){
                return false;
            }
            
        }
        return true;
    }
    void solve(int index,string s, vector<vector<string>>&ans,vector<string>&res){
        int n=s.size();
        // base ccase
        if(index==n){
            ans.push_back(res);
        }
        for(int i=index;i<n;i++){
            if(isPalindrome(index,i,s)){
                res.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,res);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>res;
        solve(0,s,ans,res);
        return ans;
        
    }
};