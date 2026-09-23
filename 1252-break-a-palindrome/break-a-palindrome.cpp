class Solution {
public:
    string breakPalindrome(string palindrome) {
        
        int n=palindrome.size();
        if(n==1) return "";
       
        bool change =false;
        for(int i=0;i<(n/2);i++){
            if(palindrome[i]!='a'){
                palindrome[i]='a';
                change=true;
                return palindrome;
            }
        }
        if(change==false || palindrome[n-1]=='a') {
           palindrome[n-1]='b'; 
           return palindrome;
        } 
        
        return "";
    }
};