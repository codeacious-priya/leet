class Solution {
public:
    int solve(int i,vector<int>&presum){
        int n=presum.size();
   
           vector<int>dp(n,0);
        // base case
        dp[n-1]=presum[n-1];
        
        if(dp[i]!=0){
            return dp[i];
        }
        for(int i=n-2;i>=1;i--){
            int take=presum[i]-dp[i+1];
            int skip=dp[i+1];

             dp[i]=max(skip,take);
        }
       return dp[1];
    }
    int stoneGameVIII(vector<int>& stones) {
        int n=stones.size();
             vector<int>presum(n,0);
        presum[0]=stones[0];
       
        for(int i=1;i<n;i++){
            presum[i]=presum[i-1]+stones[i];
        }
        return solve(1,presum);
        
    }
};