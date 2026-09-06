class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int max_idx = 0;
        for(int i=0;i<n;i++){
            if(max_idx >= n-1)return true;
            int temp =i;
            if(i<=max_idx){
                temp += nums[i];
                max_idx = max(max_idx , temp);
            }
        }
        return false;
    }
};