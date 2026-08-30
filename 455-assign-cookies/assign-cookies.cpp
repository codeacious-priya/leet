class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cnt=0;
        int m=g.size();
        int n=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

       int r=0;
       int l=0;
       while(r<n && l<m){
        if( g[l]<=s[r]){
            
            l++;
        }
        
         r++;
        

       }
       return l;
    }
};