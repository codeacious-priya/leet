class Solution {
public:
    int totalFruit(vector<int>& f) {
       unordered_map<int,int>mp;
        int n=f.size();
        int maxi=0;
        int i=0;

        for(int j=0;j<n;j++){
           mp[f[j]]++;
           while(mp.size()>2){
            mp[f[i]]--;
            if(mp[f[i]]==0){
                mp.erase(f[i]);
            }
            i++;
           }
           
        maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};