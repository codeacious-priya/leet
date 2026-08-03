class Solution {
public:
    int percentageLetter(string s, char letter) {
        int cnt=0;

        for(int i=0;i<s.size();i++){
            if(s[i]==letter){
                cnt++;
            }
        }
        if(cnt==0) return 0;
        int x = (cnt*100)/s.size();
        return x;
        
    }
};