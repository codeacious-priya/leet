class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        unordered_set<int>st;

        for(auto it:nums){
            st.insert(it);
        }
        for(auto it:st){
            if(st.count(target)){
                return true;
            }
        }

        while(s<=e){
            int mid=s+(e-s)/2;
            if(nums[mid]==target){
                return true;
            }
            if(nums[s]==target||nums[e]==target){
                return true;
            }
            //left sorted
            if(nums[mid]>nums[s]){
                if(nums[s]<target && nums[mid]>target){
                    e=mid-1;
                }
                else{
                    s=mid+1;
                }

            }
            //right sorted
            else{
                if(nums[mid]<target && nums[e]>target){
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }

            }

            
        }
        return false;
    }
};