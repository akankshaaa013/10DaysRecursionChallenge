#include<bits/stdc++.h>
using namespace std;

/*
isValid() function basically checks if there num is not present at 
any other location in the ith row and jth column and also in the mini 3X3 matrix. If the same 
number is present then it returns false else it returns true.
*/
bool isValid(vector<vector<int>> &matrix,int row,int col,int num){
    for(int i=0;i<9;i++){
        if(matrix[row][i] == num){
            return false;
        }
        if(matrix[i][col] == num){
            return false;
        }

        if(matrix[3*(row/3)+i/3][3*(col/3)+i%3] == num){
            return false;
        }
    }

    return true;
}

/*
solve() function checks through each cell of the matrix if it is empty or not. If "no" it will continue to next cell else if "YES"
it will check which number can be inserted in that cell. Once the number is inserted the solve function will be called again 
recursively and similarly it fills next cell and the call continues till the last cell is filled.
Once the last cell is filled the function returns true. Else if there exists a cell which cannot be filled
with any number, then the function returns false.
*/

bool solve(vector<vector<int>> &matrix){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(matrix[i][j] == 0){

                for(int num=1;num<=9;num++){
                    if(isValid(matrix,i,j,num)){

                        matrix[i][j] = num;

                        if(solve(matrix) == true){
                            return true;
                        }
                        else{
                            matrix[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


bool isItSudoku(vector<vector<int>> &matrix) {
    return solve(matrix);
}

int main(){

    vector<vector<int>> v = {{1 ,5, 9, 0, 0 ,6 ,0 ,3, 2},{2,7,4,0,0,0,0,0,0},{3 ,8 ,6 ,2 ,0 ,0 ,0 ,0 ,5},{4 ,9 ,2 ,5 ,0 ,1 ,0 ,8, 0},{6, 3 ,7 ,0 ,4 ,0 ,0 ,0 ,0},{5,1,0,8,2,0,0,0,0},{8,2,1,0,0,0,0,0,0},{7,6,0,1,0,0,4,2,0},{9,4,3,0,7,0,0,6,1}};
    
    if(isItSudoku(v)){
        cout<<"Yes";
    }
    else cout<<"No";

}
