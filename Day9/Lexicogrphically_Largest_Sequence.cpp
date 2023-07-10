#include<bits/stdc++.h>
using namespace std;

bool Solve(int &n,int index,vector<bool>& visited,vector<int>& ans,int left){
    
    //If left is equal to 0 it implies that the ans vector is succesfully filled and it returns true.
    if(left == 0){
        return true;
    }
    //if the current element that is been processed is not -1 then it is already filled with some digits
    //  and so we call the function recusrively for the next index.
    if(ans[index] != -1){
        return Solve(n,index+1,visited,ans,left);
    }

    /*
    Using for loop to iterate from n to 1 in descending order and placing the digits at the appropriate position.
    */

    for(unsigned int i=n;i>=1;i--){

        /*If the index is not visited and i is equal to 1 then we ste 1 at index th position and set visited[1] as true and 
        again call the function recusrively for next index and decrement left by 1. If 1 is placed at correct
        position then we return true. If 1 is not placed at appropriate position then while backtracking
        we reset ans[index] to -1 and set visited[i] to false.*/

        if(!visited[i] && i==1){
            ans[index] = 1;
            visited[i] = true;
            
            if(Solve(n,index+1,visited,ans,left-1)){
                return true;
            }

            ans[index] = -1;
            visited[i] = false;
        } else if(!visited[i]) {

            /*it checks if i assigned to ans at the current index and index+i is valid or not. 
            If the sum of index and i is greater than or equal to size of ans or if the value is already
            assigned to that position then we skip the current iteration and continue to the next.*/
            if(index+i >= ans.size() || ans[index+i] != -1){
                continue;
            }


            /*Else the ith value is assigned to current index and index + i & the function is called recurisvely again
            for the next index and left is decremnted by 2. left deotes the no. of positions that are left
            to be filled. */
            

            /*If the recursive call returns true, it means a valid sequence has been found, so it returns true.
            Otherwise, it resets the arr and visited values for the current index and continues with the next iteration.*/
            ans[index] = i;
            ans[index+i] = i;
            visited[i] = true;

            if(Solve(n,index+1,visited,ans,left-2)){
                return true;
            }
            ans[index] = -1;
            ans[index+i] = -1;
            visited[i] = false;
        }
    }
    return false;
}

vector<int> validSequence(int n){
    
    //Making ans vector is size 2n-1 and initializing it with -1.
    vector<int> ans(2*n-1, -1); 
           
    //Making a bool vector of size n+1 to deneote which digit is used and which is left to do.
    //Initializing all position with false except the 0th since 0 number is not taken into consideration.
    vector<bool> visited(n+1, false);
    
    visited[0] = true;
    
    Solve(n,0, visited, ans, 2*n-1);
    return ans;
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    vector<int> ans = validSequence(n);
    for(auto i:ans){
        cout<<i<<" ";
    }
}