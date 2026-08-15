class Solution {
public:
    bool isequal(string s1,string s2){
        int n=s2.size();
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]) return false;
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int m=haystack.size();
        int n=needle.size();

        int j=0;
        for(int i=0;i<m;i++){
            if(haystack[i]==needle[j]){
                if(isequal(haystack.substr(i,n),needle)){
                    return i;
                }
            }
        }
        return -1;
    }
};