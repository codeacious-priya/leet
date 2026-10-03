class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int m, int k,int day){
        int n=bloomDay.size();
        int count=0;
        int bouquet=0;

        for(int b:bloomDay){
            if(b<=day){
                count++;
                if(count==k){
                    bouquet++;
                    count=0;
                }
                
            }
            else{
                    count=0;
                }
        }
        return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        if(n<(long long)m*k) return -1;
        int low=1;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        int ans=-1;

        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPossible(bloomDay,m,k,mid)){
                ans=mid;
                high=mid-1;


            }
            else{
                low=mid+1;
            }
        }
    
        return ans;
    }
};