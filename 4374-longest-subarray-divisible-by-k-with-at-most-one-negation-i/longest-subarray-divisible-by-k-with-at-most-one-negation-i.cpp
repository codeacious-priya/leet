class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
       int n=nums.size();
       int maxi=0;


       for(int i=0;i<n;i++){
        int sum=0;
        unordered_set<int>st;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            int curr_rem=((sum%k)+k)%k;
            if(curr_rem==0)
                maxi=max(maxi,j-i+1);
        
            int rem=(((2*nums[j])%k)+k)%k;
            st.insert(rem);
            if(st.count(curr_rem))
                maxi=max(maxi,j-i+1);
            


        }
       }

       return maxi; 
    }
};