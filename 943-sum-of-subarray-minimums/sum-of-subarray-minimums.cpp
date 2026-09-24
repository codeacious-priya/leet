class Solution {
public:
    vector<int>prevl(vector<int>&arr){
        int n=arr.size();
        vector<int>prev(n,-1);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty()&& arr[st.top()]>arr[i]){
                st.pop();

            }
            if(!st.empty()){
                prev[i]=st.top();
            }
            st.push(i);
        }
        return prev;
    }
    vector<int>nextl(vector<int>&arr){
        int n=arr.size();
        vector<int>next(n,n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i]){
                st.pop();

            }
            if(!st.empty()){
                next[i]=st.top();
            }
            st.push(i);
        }
        return next;
    }
    int sumSubarrayMins(vector<int>& arr) {
        
        int n=arr.size();
        const int mod=1e9+7;
        vector<int>prev=prevl(arr);
        vector<int>next=nextl(arr);

        long long ans=0;

        for(int i=0;i<n;i++){
            long long leftchoice=i-prev[i];
            long long rightchoice=next[i]-i;
            long long contributions=(arr[i]*(leftchoice*rightchoice)%mod)%mod;
            ans=(ans+contributions)%mod;
        }
        return ans;
    }
};