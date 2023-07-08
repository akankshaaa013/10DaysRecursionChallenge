#include<bits/stdc++.h>
using namespace std;

void Solve(int n,int source,int dest,int aux,vector<vector<int>>& ans){

    //If there is one disc in the rod move it from source to destination i.e., push{source,dest} in the ans vector.

    if(n == 1){
        ans.push_back({source,dest});
        return;
    }

    //Calling the function recursively to move (n-1) discs from source to auxillary rod using destination rod.
    Solve(n-1,source,aux,dest,ans);

    //When the disc is moved from one rod to another, pushing the source and dest in ans vector.
    ans.push_back({source,dest});

    //Calling the function recursively to move (n-1) discs from auxillary rod to destination rod using source rod.
    Solve(n-1,aux,dest,source,ans);
}

vector<vector<int>> towerOfHanoi(int n)
{
    vector<vector<int>> ans;
    int S = 1,D=3,A=2;
    Solve(n,S,D,A,ans);    
    return ans;
}

int main(){

    int n;
    cout<<"Enter the no. of discs : ";
    cin>>n;

    vector<vector<int>> ans = towerOfHanoi(n);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<"   ";
        }
        cout<<endl;
    }

}