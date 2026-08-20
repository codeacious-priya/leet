class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>arr(n);
        arr[0]=nums[0];
        arr[n-1]=nums[1];
        int i=0;
        int j=n-1;
        for(int k=2;k<n;k++){
            if(arr[i]>arr[j]){
                arr[++i]=nums[k];
            }
            else{
                arr[--j]=nums[k];
            }
        }
        reverse(arr.begin()+j,arr.end());
        return arr;
    }
};