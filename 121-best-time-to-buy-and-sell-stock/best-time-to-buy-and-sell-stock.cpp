class Solution {
public:
    int maxProfit(vector<int>& p) {
        int mini=INT_MAX;
        int ans=0;
        int n=p.size();

        for(int i=0;i<n;i++){
            if(mini>p[i]){
                mini=p[i];
            }
            int profit=p[i]-mini;
            ans=max(ans,profit);
            
        }
        return ans;
    }
};