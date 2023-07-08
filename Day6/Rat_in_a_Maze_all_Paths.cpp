#include <bits/stdc++.h>
using namespace std; 

void Solve(vector<vector<int>> &maze, int n, vector<vector<int> > &ans, vector<int>&temp, int row, int col){

    /* Base Case to check if previous row or col doesn't exists or if row or col goes out of range
    or if the temp vector contains 1 at position [i][j] or to check if the path is available or not
    then the reursive call should return/terminate.
    */
    if(row<0 || row>=n || col<0 || col>=n || maze[row][col]==0 || temp[row*n+col]==1){
        return;
    }

    //if we have reached our destination cell i.e., [n-1][n-1] then marks the last cell as 1 and push it into the naswer vector
    
    if(row == n-1 && col==n-1)
    {
        temp[row*n+col] = 1;
        ans.push_back(temp);
    }

    // While calling the function recursively , marking the current position as 1 indicating that the cell is already visited.
    temp[row*n+col] = 1;

    //Recursively calling the function for Downwards direction.
    Solve(maze,n,ans,temp,row,col+1);
    //Recursively calling the function for Left direction.
    Solve(maze,n,ans,temp,row-1,col);
    //Recursively calling the function for Right direction.
    Solve(maze,n,ans,temp,row,col-1);
    //Recursively calling the function for Upwards direction.
    Solve(maze,n,ans,temp,row+1,col);

    //While Backtracking making sure that the current position is unmarked and the function is called recusrively for the next direction.
    temp[row*n+col] = 0;
}

vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans;

    //Creating a temp vector of size n*n to store the possible paths but before that initializing all cells with 0.
    
    vector<int>temp(n*n,0);

    Solve(maze,n,ans,temp,0,0);
    return ans;
}

int main(){

    int n;
    cout<<"Enter the size of the vector : ";
    cin>>n;

    vector<vector<int>> v;
    cout<<"Enter the vector elements : \n";

    for(int i = 0;i<n;i++){
        vector<int> vtemp;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            vtemp.push_back(a);
        }
        v.push_back(vtemp);
    }

    vector<vector<int>> ans = ratInAMaze(v,n);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<"   ";
        }
        cout<<endl;
    }

}