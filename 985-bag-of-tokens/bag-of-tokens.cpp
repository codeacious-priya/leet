class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        sort(tokens.begin(),tokens.end());
        int i=0;
        int j=n-1;
        int score =0;
        int maxiscore=0;
        if(n==0) return 0;
      

        if(i==0 && power<tokens[i]){
               return 0;
            }

        while(i<n){

            if(i==0 || (power>=tokens[i])){
                score++;
                maxiscore=max(maxiscore,score);
                power-=tokens[i];
                i++;
            }
            else if(j>0 && score>=1){
                score--;
                
                power+=tokens[j];
                j--;
            }
            

        }
        return maxiscore;
    }
};