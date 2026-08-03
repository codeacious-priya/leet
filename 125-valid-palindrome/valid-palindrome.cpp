class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z'){
                char ch= tolower(s[i]);
                ans.push_back(ch);
            }
            else if(s[i]>='a'&&s[i]<='z'||s[i]>='0'&&s[i]<='9'){
                ans.push_back(s[i]);
            }
            else{
                continue;
            }
        }
        
        int i=0;
        int j=ans.size()-1;
        while(i<j){
            if(ans[i]!=ans[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};