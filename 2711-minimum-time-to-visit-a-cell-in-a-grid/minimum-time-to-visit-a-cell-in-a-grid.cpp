class Solution {
  #define P pair<int , pair<int , int >>
  vector<vector<int >>direction = {{0 , 1}, {0,-1} , {1 , 0}  , {-1 , 0}};
public:
    int minimumTime(vector<vector<int>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      // Base case if {0 , 1} -> 1000
      // {1 , 0} -> 1500 
       if(grid[0][1] > 1 && grid[1][0] > 1){

        return -1;
      }

      // dijstra' s algorithm
      // Time Complexity of dijstra (E * log (V))
      // E = number of edges
      // v = number of vertex
      priority_queue<P , vector<P> , greater<P>>pq ; // min heap
      vector<vector<int>>result(m , vector<int>(n ,INT_MAX));
      result[0][0] = 0;
      pq.push({0 , {0 , 0}}); // time and min time for [i][j]
      vector<vector<bool>> visited(m , vector<bool>(n , false));
      while(!pq.empty()){
        int time = pq.top().first;
        // time {i , j}
        int row  = pq.top().second.first; 
        int col = pq.top().second.second;
        pq.pop(); 
        if(row == m-1 && col == n-1){
          return result[m-1][n-1]; // destination node
        }
        if(visited[row][col] == true){
          continue;
        }
        visited[row][col] = true;

        // for all possible direction 
        for(auto &dir : direction){
          int i = row + dir[0];
          int j = col + dir[1];

          if (i<0 || i>= m || j < 0 || j >= n ){
            continue; // check for out of bound  or less than 0
          }
          if(grid[i][j] <= time + 1){
            pq.push({time + 1 , {i , j}});
            result[i][j] = time + 1;
          }

          // difference between time and grid is even
          else if((grid[i][j] - time) % 2 == 0){
            
            pq.push({grid[i][j] + 1 , {i , j}});
            result[i][j] = grid[i][j] + 1;
          }
          else { 
            // odd 
            pq.push({grid[i][j] , {i , j}});
            result[i][j] = grid[i][j];
          }
        }

      }
      return result[m-1][n-1] == INT_MAX ? -1 : result[m-1][n-1] ;
    }
};