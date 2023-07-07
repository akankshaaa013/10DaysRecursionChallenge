#include <bits/stdc++.h> 
using namespace std;

void Solve(vector<int>&factors,unsigned int index,vector<vector<int>>&ans,vector<int>&curr,int n) {
	
	// If the index is equal to the size of factor vector & n is 1 then we have found one 
	// of the possible combinations of factors and we push it into the answer vector & return the call.

	if(index==factors.size()) {
		if(n==1) {
			ans.push_back(curr);
		}
		return;
	}

	// if n%current factor element is 0 then we proceed to call the recursive function twice.
	// Once when we again consider the same element and other when we move the index to point to the next element.
	// If considering the same element then we push it into the curr vector and call the function recursively.
	// while backtracking we need to make sure that previous orignal state of the vector is restored. So we pop the last element.

	if(n % factors[index]==0){
		curr.push_back(factors[index]);
		Solve(factors,index,ans,curr,n/factors[index]);
		curr.pop_back();
		Solve(factors,index+1,ans,curr,n);
        } 
		else {
          Solve(factors, index + 1, ans, curr, n);
        }
}

vector<vector<int>> factorCombinations(int n) {
	vector<vector<int>>ans;

	/*Making a vector factor in which all the digits from 2-(n-1) didvisible by n is stored.
	So the recursive function will be called only for these digits.*/
	vector<int>factors;
	for(int i=2;i<n;i++) {
		if(n%i==0) {
			factors.push_back(i);
		}
	}

	//curr vector to store the current factor combination.
	vector<int>curr;
	Solve(factors,0,ans,curr,n);
	return ans;
}

int main(){

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    vector<vector<int>> ans = factorCombinations(n);

    for(auto i:ans){
        for(auto j:i){
            cout<<j<<"  ";
        }
        cout<<endl;
    }

}