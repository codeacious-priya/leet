class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int max_idx = 0;
        int cnt =1;
        if(n==1)return 0;
        int i = 0;
        while(i<n){
             int maxi  = i + nums[i];
             if(maxi >= n-1)return cnt;
             int j=i+1;
             max_idx = i;
             while(j <= maxi && j<n){
                if(j+nums[j]> max_idx + nums[max_idx]){
                    max_idx = j;
                }
                j++;
             }
             i = max_idx;
             cnt++;
        }
        return -1;
    }
};