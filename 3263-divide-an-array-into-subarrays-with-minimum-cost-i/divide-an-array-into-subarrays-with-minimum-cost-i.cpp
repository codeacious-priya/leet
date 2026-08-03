class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int a=nums[0];
        sort(nums.begin()+1,nums.end());
        int sum=0;
        
        if(nums.size()==3) return sum=nums[0]+nums[1]+nums[2];
        if(a==nums[0]){
            sum=nums[0]+nums[1]+nums[2];

        }
        else{
            sum+=a;
            sum+=nums[0];
            sum+=nums[1];
        }
        return sum;

        
    }
};