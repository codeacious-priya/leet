class Solution {
public:
   vector<string>ans;
   void dfs(int i,string path,long long resSoFar,long long prevNum,string s,int target){
    if(i==s.size()){
        if(resSoFar==target){
            ans.push_back(path);
        }
        return;
    }
     for (int j = i; j < s.length(); j++) {

            // Skip numbers with leading zero
            if (j > i && s[i] == '0') {
                break;
            }

            long long currNum = stoll(s.substr(i, j - i + 1));

            // First number: don't add any operator
            if (i == 0) {
                dfs(j + 1, path + to_string(currNum),currNum,currNum,
                    s,
                    target);
            }
            else {

                // Addition
                dfs(j + 1,
                    path + "+" + to_string(currNum),
                    resSoFar + currNum,
                    currNum,
                    s,
                    target);

                // Subtraction
                dfs(j + 1,
                    path + "-" + to_string(currNum),
                    resSoFar - currNum,
                    -currNum,
                    s,
                    target);

                // Multiplication
                dfs(j + 1,
                    path + "*" + to_string(currNum),
                    resSoFar - prevNum + prevNum * currNum,
                    prevNum * currNum,
                    s,
                    target);
            }
        }
   }
    vector<string> addOperators(string num, int target) {
       ans.clear();
        dfs(0,"",0,0,num,target);
        return ans;
        
    }
};