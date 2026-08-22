class Solution {
public:
    bool checkDivisibility(int n) {
        int number=n;
        int digitsum=0;
        int digitproduct=1;
        while(n){
            int digit=n%10;
            digitsum+=digit;
            digitproduct*=digit;
            n=n/10;
        }
        int sum=(digitsum+digitproduct);
        if(sum!=0 && number%sum==0) {return true;}

        return false;
        
    }
};