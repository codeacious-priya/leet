class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
       vector<int>nums(3,0);
        int i=0;
        int ans=0;
        int cnt=0;

        for(int j=0;j<n;j++){
            nums[s[j]-'a']++;
            while(nums[0]>0 && nums[1]>0 && nums[2]>0){
                ans+=n-j;
                nums[s[i]-'a']--;
                i++;
            }
           


        }
        return ans;
    }
};