#include<bits/stdc++.h>
using namespace std;

void Solve(string& str,int i,int j,vector<string>& ans){
    
    //If both i and j are equal to 0 then we have succesfully 
    // found one possible parenthesis combination and we push it into the ans vector.
    // All the possible combinations are stored in the ans vector.
    
    if(i==0 && j == 0){
        ans.push_back(str);
        return;
    }

    // if i is equal to j or i is greater than 0 then we call the function recursively for the opening braces.
    // Also while backtracking it is important that the previous state of the str is restored 
    // so we keep popping the last character with each function return.
    
    if(i == j || i>0){
        str.push_back('(');
        Solve(str,i-1,j,ans);
        str.pop_back();
    }

    // if i is less than j then we call the function recursively for closing braces.
    // Also while backtracking it is important that the previous state of the str is restored 
    // so we keep popping the last character with each function return.
    

    if(i < j){
        str.push_back(')');
        Solve(str,i,j-1,ans);
        str.pop_back();
    }
}

vector<string> validParenthesis(int n){
    
    long long int x =n , y = n;

    vector<string> ans;
    string res="";
    
    Solve(res,x,y,ans);
    
    return ans;
       
}

int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    vector<string> ans = validParenthesis(n);

    for(auto i : ans){
        cout<<i<<"\t";
    }
}