class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        bool isopen=false;
        string ans="";
        string temp="";
        unordered_map<string,string>mp;
        for(auto it:knowledge){
            mp[it[0]]=it[1];
        }

        int i=0;
        while(i<n){
            if((s[i]=='(' )){
                isopen=true;
                i++;
               
                

            }
            else if(s[i]==')'){
                isopen=false;
                if(mp.find(temp)==mp.end()){
                    ans+='?';
                }
                else{
                   ans+=mp[temp];
                }
                
                temp="";
                i++;
            }
            else if(isopen){
                temp+=s[i];
                i++;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};