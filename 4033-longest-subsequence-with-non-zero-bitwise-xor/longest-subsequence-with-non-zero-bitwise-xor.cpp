class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();

        bool allxor=true;
        int ansXor=0;

        for(int it:nums){
            ansXor^=it;

            if(it!=0){
                allxor=false;

            }
        }
        if(allxor){
            return 0;
        }
      return ansXor==0?n-1:n;  
    }
};