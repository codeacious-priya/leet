class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);

        }
        int cnt=0;
        for(auto it:mp){
           vector<int>cmp=it.second;
           for(int i=0;i<cmp.size()-1;i++){
            if(cmp[i]!=cmp[i+1]-1){
                cnt++;
                break;
            }
           }
        }

        return mp.size()-cnt;
    }
};