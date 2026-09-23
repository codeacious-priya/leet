class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty()&& st.top()>0 && asteroids[i]<0){
                if(abs(st.top())<abs(asteroids[i])){
                    st.pop();
                    
                }
                else if(abs(st.top())>abs(asteroids[i])){
                    asteroids[i]=0;
                }
                else{
                    asteroids[i]=0;
                    st.pop();
                    break;
                }
            }
            if(asteroids[i]!=0){
                st.push(asteroids[i]);
            }
        }
        vector<int>ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans; 
    }
};