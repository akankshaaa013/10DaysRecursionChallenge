#include<bits/stdc++.h>
using namespace std;

void Solve(unsigned int index,vector<int>& candidates, int target,vector<int>& result,vector<vector<int>> &ans){

        /*
        If the index is equal to size of the input array & if target is 0 then it implies that
        we have succesfully found one combination whose sum is equal to 0
        and so we push that combination in the ans vector and return the call.
        */
        if(target == 0){
            ans.push_back(result);
            return;
        }

        if(index == candidates.size()){
            return;
        }

        /*
        If we are considering the current element and the target has to be greater than or equal to candidates[index]
        then we proceed further and call the function recursively not before pushing the current element into
        the vector.

        In order to restore the orignal vector(Vector is passed through reference), we pop the last element once the function returns. This is Called BACKTRACKING.

        */
        if(candidates[index] <= target){
            result.push_back(candidates[index]);
            Solve(index,candidates,(target - candidates[index]),result,ans);
            result.pop_back();
        }

        //Not considering the current element and moving to the next index.
        Solve(index+1,candidates,target,result,ans);

    }
vector<vector<int>> combSum(vector<int> &ARR, int B)
{
    vector<vector<int>> ans;
    vector<int> result;
    sort(ARR.begin(),ARR.end());
     
    Solve(0,ARR,B,result,ans);

    return ans;

}

int main(){
    vector<int> v;
    int n;
    cout<<"Enter the size of the vector : ";
    cin>>n;

    cout<<"Enter the vector elements : ";

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    int target;
    cout<<"Enter the target sum : ";
    cin>>target;

    vector<vector<int>> ans = combSum(v,target);

    for(auto i : ans){
        for(auto j : i){
            cout<<j<<"   ";
        }
        cout<<endl;
    }
}