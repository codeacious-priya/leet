class Solution {
public:
    int memo[501][501];
    int solve(vector<int>&piles,int i, int j){
        if(i>j){
            return 0;
        }
        if(memo[i][j] != -1)return memo[i][j];
        int pickLeft = piles[i]-solve(piles,i+1,j);
        int pickRight = piles[j]-solve(piles,i,j-1);
        
        return memo[i][j] =  max(pickLeft,pickRight);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        memset(memo,-1,sizeof(memo));
        return true;
    }
};