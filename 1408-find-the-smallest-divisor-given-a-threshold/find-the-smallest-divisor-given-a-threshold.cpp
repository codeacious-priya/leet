class Solution {
public:
    int solve(vector<int>& nums, int threshold,int mid){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=((nums[i]+mid-1)/mid);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=high;

        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=solve(nums,threshold,mid);

            
            if(sum<=threshold){
                
                ans=mid;
                high=mid-1;
            }
            else{
               low=mid+1;
            }
        }

        return ans;
    }
};