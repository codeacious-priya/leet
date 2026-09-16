class Solution {
public:
    bool isPalindrome(string &temp){
        int i=0;
        int j=temp.size()-1;
        while(i<=j){
            if(temp[i]!=temp[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
    int solve(int i,string &s,vector<int>&dp){
        int n=s.size();
        if(i>=n) return 0;
        string temp="";
        int mincost=1e7;
        if(dp[i]!=-1) return dp[i];

        for(int j=i;j<n;j++){
            temp+=s[j];
            if(isPalindrome(temp)){
                int cost=1+solve(j+1,s,dp);
                mincost=min(mincost,cost);
            }
        }
        return dp[i]=mincost;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(0,s,dp)-1;
        
    }
};