class Solution {
public:
    char solve(vector<char>&arr,char op){
        if(op=='!'){
            return arr[0]=='f'?'t':'f';
        }
        if(op=='&'){
            for(int i=0;i<arr.size();i++){
                if(arr[i]=='f') return 'f';
            }
            return 't';
        }
        if(op=='|'){
            for(int i=0;i<arr.size();i++){
                if(arr[i]=='t') return 't';
            }
            return 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        int n=expression.size();

        for(int i=0;i<n;i++){
            if(expression[i]==',') continue;

            else if(expression[i]==')'){
                vector<char>arr;
                while( !st.empty() && st.top()!='('){
                    arr.push_back(st.top());
                    st.pop();

                }
                st.pop();
                char op=st.top();
                st.pop();
                char ans=solve(arr,op);
                st.push(ans);

            }
            else{
                st.push(expression[i]);
            }

           
        }

        return st.top()=='t'?true:false;
    }
};