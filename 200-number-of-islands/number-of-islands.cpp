class Solution {
public:
    int m,n;
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>&vis){

        if(i<0||i>=m||j<0||j>=n||grid[i][j]=='0') return;
        vis[i][j]=1;

        if(i+1<m && !vis[i+1][j] && grid[i+1][j]=='1'){
            dfs(i+1,j,grid,vis);
        }
        if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]=='1'){
            dfs(i-1,j,grid,vis);
        }
        if(j+1<n && !vis[i][j+1] && grid[i][j+1]=='1'){
            dfs(i,j+1,grid,vis);
        }

        if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]=='1'){
                    dfs(i,j-1,grid,vis);
                }
    }
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        vector<vector<int>>vis(m,(vector<int>(n,0)));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        
       return count; 
    }
};