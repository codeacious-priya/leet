class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int a= -1;int b= -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
               a=i;
               break;
            }
            

        }
         if (a == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i=n-1;i>a;i--){
            
            if(nums[i]>nums[a]){
                b=i;
                break;
            }
        }
       
        swap(nums[a],nums[b]);
        reverse(nums.begin()+a+1,nums.end());
        
    }
};