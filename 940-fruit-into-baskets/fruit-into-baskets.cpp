class Solution {
public:
    int totalFruit(vector<int>& f) {
       unordered_map<int,int>mp;
        int n=f.size();
        int len=0;
        int maxi=0;
        int i=0;

        for(int j=0;j<n;j++){
           mp[f[j]]++;
           if(mp.size()<=2){
            len=j-i+1;
            maxi=max(maxi,len);
           }
           else{
            mp[f[i]]--;
            if(mp[f[i]]==0){
                mp.erase(f[i]);
            }
            i++;
           }
           

        }
        return maxi;
    }
};