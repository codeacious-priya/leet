class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        unordered_set<int>st;

        for(auto it:nums){
            st.insert(it);
        }
        int start=nums[0];
        int end=nums[n-1];

        for(int i=start;i<=end;i++){
            if(st.find(i)==st.end()){
              ans.push_back(i);
            }
        }
     return ans;
        
    }
};