class Solution {
public:
    bool isequal(string s,string t){
        int n=t.size();
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
    }
    int strStr(string s, string t) {
        int n=s.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]==t[j]){
                if(isequal(s.substr(i,n),t)){
                    return i;
                }
            }
        }
        return -1;
    }
};