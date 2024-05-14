class Solution {
public:

    int m,n;

    int dfs(vector<vector<int>>& grid, int i , int j){

        if(i>=m || j>=n || i<0 || j<0 || grid[i][j]==0){
            return 0;
        }

        int originalGoldValue = grid[i][j];
        grid[i][j] = 0;

        int maxGold = 0;

        maxGold = max(max(dfs(grid, i-1 , j),dfs(grid,i+1 , j)) , max(dfs(grid, i,j+1), dfs(grid,i,j-1)));


        grid[i][j] = originalGoldValue;
        return originalGoldValue + maxGold ;

    }

    int getMaximumGold(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        
        int maxSum = 0;
        for(int i=0 ; i<m ; i++){
            for(int j=0 ; j<n ; j++){

                if(grid[i][j] != 0){
                    maxSum = max(maxSum , dfs(grid, i ,j));
                }

            }
        } 

        return maxSum;
    }
};