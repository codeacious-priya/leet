class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int res=2;
        int prod=1;
        int i=0,j=0;

        while(j<n){
            while(gcd(prod,nums[j])>1){
                prod/=nums[i];
                i++;
            }
            prod*=nums[j];
            res=max(res,j-i+1);
            j++;
        }

        return res;
        
    }
};