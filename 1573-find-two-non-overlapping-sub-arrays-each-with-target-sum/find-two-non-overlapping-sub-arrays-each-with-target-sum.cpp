class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        int currsum=0;
        vector<int>minbestlentillidx(n+1,INT_MAX);
        int result=INT_MAX;
        int bestminlen=INT_MAX;

        while(j<n){
            currsum+=arr[j++];
            while(i<j && currsum>target){
                currsum-=arr[i];
                i++;
            }
            if(currsum==target){
                int len=j-i;
                if(i>0 && minbestlentillidx[i]!=INT_MAX){
                    result=min(result,len+minbestlentillidx[i]);
                }
                bestminlen=min(bestminlen,len);

            }
            minbestlentillidx[j]=bestminlen;
        }

    return result==INT_MAX?-1:result;
        
    }
};