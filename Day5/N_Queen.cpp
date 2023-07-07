#include<bits/stdc++.h>
using namespace std;

bool isvalid(vector<vector<int>> &arr,int row,int col,int n)
{
    int r=0,c=0;

    //Loop for checking the previous LEFT elements.
    while(c<n)
    {
        if(c==col)
        {
            c++;
            continue;
        }
        if(arr[row][c]==1)
          return false;
        c++;
    }

    //Loop for checking the Upper Diagonal Elements.
    r=row,c=col;
    while(r>=0 && c>=0)
    {
        if(arr[r][c]==1)
          return false;
        r--,c--;
    }

    //Loop for checking the Lower Diagonal Elements.
    r=row,c=col;
    while(r<n && c>=0)
    {
        if(arr[r][c]==1)
          return false;
        r++,c--;
    }

    return true;
}


void solve(int col,int n,vector<vector<int>> &arr,vector<vector<int>> &ans)
{
    //If the base condition is satisfiedi.e., col is equal to n then we have succesfully deduced 
    //one of the solutions and so we push it in ans vector.
    if(col==n)
    {
        vector<int> temp;
        for(auto it:arr)
        {
            for(int i=0;i<it.size();i++)
                temp.push_back(it[i]);
        }  
        ans.push_back(temp);
        return;
    }

/*
Iterating throgh each row and calling the function recursively
for next column. Once the function returns we have to restore the previous state
of the board so re-setting the ith row & jth col to 0.
*/
    for(int i=0;i<n;i++)
    {
        if(isvalid(arr,i,col,n))
        {
            arr[i][col]=1;
            solve(col+1,n,arr,ans);
            arr[i][col]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {

    //declaring a 2-D vector arr of size n ans initializing eah sub-vector of size n as 0. This is crucial since initially
    //we consider that all the places on the board is initialized with 0.

    vector<vector<int>> arr(n,vector<int>(n,0));

    vector<vector<int>> ans;

    solve(0,n,arr,ans);

    return ans;
}

int main(){
    int n;
    cout<<"Enter the no. of Queens : ";
    cin>>n;

    vector<vector<int>> arr = solveNQueens(n);

    for(auto i:arr){
        for(auto j:i){
            cout<<j<<"   ";
        }
        cout<<endl<<endl;
    }

}