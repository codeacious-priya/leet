class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int last_a=-1;
        int last_b=n;

        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                last_a=max(last_a,i);
            }
            if(s[i]=='b'){
                last_b=min(last_b,i);
            }
        }
        if(last_a<last_b){
            return true;
        }
        return false;
    }
};