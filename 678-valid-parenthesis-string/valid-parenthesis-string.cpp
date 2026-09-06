class Solution {
public:
    bool checkValidString(string s) {
        int opencnt=0;
        int closecnt=0;
        int len=s.size()-1;

        for(int i=0;i<=len;i++){
            if(s[i]=='('||s[i]=='*'){
                opencnt++;
            }
            else{
                opencnt--;
            }
            if(s[len-i]==')'|| s[len-i]=='*'){
                closecnt++;
            }
            else{
                closecnt--;
            }
            if(opencnt<0 || closecnt<0){
            return false;
       }
        }
       
        return true;
    }
};