// leetcode problem link below for pracice

// https://leetcode.com/problems/unique-paths-iii/


 //      Approach 
 /*
 1. -> first we will find the number of non_obstcle block and coordinate of the starting points

 2-> if we visit the block we will mark it visited by changing 0 with -1

 3-> if we encounter a 2 i.e the final state we will check the cnt is equal to number of non obstcle if not then return ,
 and if it is equal then we will increase the number of paths and then return  and backtrack it and change -1 to 0; for 
 next backtracing call 
 */


class Solution {

    int row,col;
    int unique_path;
    int non_obstcle;

    vector<vector<int>> directions {{1,0},{-1,0},{0,-1},{0,1}};

    void solve(vector<vector<int>>& grid,int cnt, int x, int y){

        // base case and out of boundation and obstcle check
        if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == -1) return;

        // if we visit the 2 i.e the finishing point and also chack the non_obstcle 
        // according to the problem we have to visit all non obstcle block 
        if(grid[x][y] == 2){
            if(non_obstcle == cnt) 
                unique_path++;
            return;
        }

        grid[x][y] = -1; // this mark the block as the visited block

        // we have to explore all the possible direction
        for(vector<int> &it : directions){
            int new_x = x + it[0];
            int new_y = y + it[1];
            solve(grid,cnt+1,new_x,new_y);
        }
        grid[x][y] = 0; // we main the character of block for next call
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        unique_path = 0;
        non_obstcle = 0;
        int start_x = 0;
        int start_y = 0;

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == 0) 
                    non_obstcle++;

                else if(grid[i][j] == 1){
                    non_obstcle++;
                    start_x = i;
                    start_y = j;
                } 
            }
        }

        int obstcle_cnt = 0;
        solve(grid,obstcle_cnt,start_x,start_y);
        return unique_path;  
    }
}; 


