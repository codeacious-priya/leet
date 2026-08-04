class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int n=s.size();
        int len=0;
        int i=0;
        int maxi=0;

        for(int j=0;j<n;j++){
            mp[s[j]]++;
             maxi=max(maxi,mp[s[j]]);
            while(j-i+1 - maxi>k){
                mp[s[i]]--;
                i++;
            }
            len=max(len,j-i+1);
        }
        return len;
        
    }
};