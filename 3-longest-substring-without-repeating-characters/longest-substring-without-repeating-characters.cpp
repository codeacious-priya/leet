class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        int len=0;
        int maxlen=0;

        vector<int>hash(256,-1);
        for(int j=0;j<n;j++){
            if(hash[s[j]]>=i){

                i=hash[s[j]]+1;
            }
            hash[s[j]]=j;
            len=j-i+1;
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};