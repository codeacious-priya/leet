class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        for(int j=0;j<n;j++){
            if(s[j]==')'){
                int i=j-1;
                while(s[i]!='('){
                    i--;
                }
                s[i]='#';
                s[j]='#';
                reverse(s.begin()+i+1,s.begin()+j);
            }
        }
        string ans = "";
        for(auto it: s){
            if(it!='#')ans+=it;
        }
        return ans;
        
        //debug karo na ji kaha galat ho rha
        // aise nhi hog
        //ok
       // jo mai soch rahi thi vo nhi ho sakkta 
       // wrong ans ayega
       //ha sahi baat hai 
       //two pointer se ho skta hai karo 
       // kar rahi ?????
       // inner bracket ko reverse karenge fir outer bracket ko toh sahi hoga
    }
};