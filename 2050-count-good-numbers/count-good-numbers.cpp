class Solution {
public:
     const int M=1e9+7;
    int power(long long base,long long power){
        base%=M;
        long long result=1;

        while(power>0){
            if(power%2==1){
                result=(result*base)%M;

            }
            base=(base*base)%M;
            power/=2;
        }
        return result%M;
    }
   
    int countGoodNumbers(long long n) {
        long long ans;
        if(n%2==0){
            long long even=(power(5,(n+1)/2))%M;
            long long odd=(power(4,n/2))%M;
            ans=(even*odd)%M;

        }
        else if(n%2==1){
            long long even=(power(5,(n+1)/2))%M;
            long long odd=(power(4,(n/2))%M);
            ans=(even*odd)%M;

        }
    return ans%M;
        
    }
};