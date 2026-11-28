class Solution {
public:
    
    
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
    
     vector<long long>prev(m+1,0),curr(m+1,0);
       // delete
       for(int i=0;i<=n;i++){
        prev[0]=i;
       }
       //insert
       for(int j=0;j<=m;j++){
       prev[j]=j;
       }
       
       for(int i=1;i<=n;i++){
         curr[0]=i;
        for(int j=1;j<=m;j++){
            if(word1[i-1]==word2[j-1]){
                curr[j]=prev[j-1];
            }
            else{
                int del=1+prev[j];
                int insert=1+curr[j-1];
                int replace=1+prev[j-1];

               curr[j]=min({del,insert,replace});
            }
        }
        prev=curr;
       }
        return prev[m];
    }
};