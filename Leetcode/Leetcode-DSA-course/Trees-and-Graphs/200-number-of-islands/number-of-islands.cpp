class Solution {
public:
    int m,n;
    vector<vector<int>> directions={{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<char>> grid;
    vector<vector<bool>> seen;

    int numIslands(vector<vector<char>>& grid) {
        this->grid=grid;
        m=grid.size();
        n=grid[0].size();
        seen=vector(m,vector<bool>(n,false));

        int ans=0;
        for(int row=0;row<m;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]=='1' && !seen[row][col]){
                    seen[row][col]=true;
                    ans++;
                    dfs(row,col);
                }
            }
        }
        return ans;
    }

    void dfs(int row,int col){
        for(vector<int> &direction:directions){
            int nextRow=row+direction[0];
            int nextCol=col+direction[1];
            if(isValid(nextRow,nextCol) && !seen[nextRow][nextCol]){
                seen[nextRow][nextCol]=true;
                dfs(nextRow,nextCol);
            }
        }
    }

    bool isValid(int row, int col){
        return row>=0 && row<m && col>=0 && col<n && grid[row][col]=='1';
    }
};