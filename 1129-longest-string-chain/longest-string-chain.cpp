class Solution {
public:
    bool iscompare(string &s1,string &s2){
        if(s1.size()!=s2.size()+1) return false;
        int first=0;
        int second=0;

        while(first<s1.size()){
            if(second<s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        if(first==s1.size() && second==s2.size()) return true;

        return false;
    }
    static bool cmp(string s1,string s2){
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);
        vector<int>dp(n+1,1);
        int max_len=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(iscompare(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                }
               
            }
            if(max_len<dp[i]){
                max_len=dp[i];
            }
        }
        return max_len;
    }
};