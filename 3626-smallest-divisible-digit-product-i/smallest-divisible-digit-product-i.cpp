class Solution {
public:
    int solve(int n){
        int digit =1;
        while(n>0){
             digit*=(n%10);
            n=n/10;
        }
        return digit;
    }
    int smallestNumber(int n, int t) {
        
        for(int i=n;i<=n*t;i++){
            if(solve(i)%t==0) return i ;
        }
       

        return 0;
    }
};