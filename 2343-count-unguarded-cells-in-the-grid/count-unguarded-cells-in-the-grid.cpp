class Solution {
public:
    
    void dfs(vector<char> grid[], int x, int y, int m, int n)
    {
        for(int row = x-1;row>=0;row--)
        {
            if(grid[row][y]=='W' || grid[row][y]=='G')
                break;
            grid[row][y] = '-';
        }
        
        for(int row = x+1;row<m;row++)
        {
            if(grid[row][y]=='W' || grid[row][y]=='G')
                break;
            grid[row][y] = '-';
        }
        
        for(int col = y-1;col>=0;col--)
        {
            if(grid[x][col]=='W' || grid[x][col]=='G')
                break;
            grid[x][col] = '-';
        }
        
        for(int col = y+1;col<n;col++)
        {
            if(grid[x][col]=='W' || grid[x][col]=='G')
                break;
            grid[x][col] = '-';
        }
        
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) 
    {
        vector<char> grid[m];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                grid[i].push_back('.');
            }
        }
        
        for(int i=0;i<walls.size();i++)
        {
            grid[walls[i][0]][walls[i][1]] = 'W';
        }
        
        for(int i = 0;i<guards.size();i++)
        {
            int x = guards[i][0];
            int y = guards[i][1];
            grid[x][y] = 'G';
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='G')
                    dfs(grid,i,j,m,n);
            }
        }
        
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='.')
                    count++;
            }
        }
        return count;
    }
};













