class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt=0;
        int far=0;
        int current=0;
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            far=max(far,i+nums[i]);

            if(i==current){
                cnt++;
                current=far;
            }
        }
        return cnt;
    }
};