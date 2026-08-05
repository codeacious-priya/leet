class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>suspicios(n,0);
        vector<int>indegree(n,0);

        for(auto it:invocations){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int>q;
        q.push(k);
        suspicios[k]=1;
        

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto nbr:adj[node]){
                indegree[nbr]--;
                if(!suspicios[nbr]){
                    suspicios[nbr]=1;
                    q.push(nbr);
                }
            }
        }
        vector<int>res;
       
        for(int i=0;i<n;i++){
            if(suspicios[i]&& indegree[i]>0){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;

            }
            if(!suspicios[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};