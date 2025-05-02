class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    //    i-1 j-1      i,j
    //    row->y
    //    col->x
    //    row v
    //    col >
       vector<int>rowMin(n+1,INT_MAX),rowMax(n+1,INT_MIN);
       vector<int>colMin(n+1,INT_MAX),colMax(n+1,INT_MIN);
       for(auto it: buildings){
            int x=it[0];
            int y=it[1];
            rowMin[x]=min(rowMin[x],y);
            rowMax[x]=max(rowMax[x],y);
            colMin[y]=min(colMin[y],x);
            colMax[y]=max(colMax[y],x);
       }
       int o=0;
       for(auto it: buildings){
        int x=it[0],y=it[1];
        if((y > rowMin[x] && y < rowMax[x]) && (x > colMin[y] && x < colMax[y])) o++;

       }
       return o;
    }
};