class Solution {
public:
    void solve(int n, string temp, int open, int close, vector<string>&ans){
        if(open==n && close ==n){
            ans.push_back(temp);
            return;
        }
        if(open < n){
            solve(n,temp+'(', open+1, close, ans);
        }
        if(close < open){
            solve(n, temp+')', open, close+1, ans);
        }                  
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        solve(n, "", 0, 0, ans);
        return ans;
    }
};