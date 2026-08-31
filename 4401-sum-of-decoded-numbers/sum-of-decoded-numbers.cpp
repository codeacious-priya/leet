class Solution {
public:
    const int mod=1e9+7;
    long long pow(long long base,long long exp){
        long long res=1;
        base%=mod;
        while(exp>0){
            if(exp%2==1) res=(res*base)%mod;
            base=(base*base)%mod;
            exp/=2;
        }
        return res;
    }
    long long solve(long long num){
        int w=num%10;
        long long d=floor(num/10);
        string s=to_string(d);
        string x=s.substr(0,w);
        string y=s.substr(w);
       long long xx= stoll(x)%mod;
       long long yy= stoll(y);
        long long ans= pow(xx,yy);
        
        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            long long val=solve(nums[i])%mod;
            sum=(sum+val)%mod;

        }
        return sum%mod;
    }
};