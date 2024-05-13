class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        for(int i=0 ; i<m ; i++){
            if(grid[i][0]==0){
                for(int j=0 ; j<n ; j++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }else{
                        grid[i][j]=0;
                    }
                }
            }
        }

        for(int j=0 ; j<n ; j++){
            int cntz = 0;
            int cnto = 0;
            for(int i=0 ; i<m ; i++){
                if(grid[i][j]==1){
                    cnto++;
                }else{
                    cntz++;
                }
            }

            if(cntz>cnto){
                for(int i=0 ; i<m ; i++){

                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }else{
                        grid[i][j]=0;
                    }
                }
            }
        }

        int score = 0;

        for(int j=0 ; j<m ; j++){
            int binary = 0;
            int exp = 0;
            for(int i=n-1 ; i>=0 ; i--){
                if(grid[j][i]==1){
                    binary += pow(2,exp);
                }
                exp++;
            }

            score += binary;
        }

        return score;
        
    }
};