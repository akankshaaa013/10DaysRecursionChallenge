#include<bits/stdc++.h>
using namespace std;

void solve(unsigned int index,string &s,vector<string> &ans){
    
    /*
    The below if condition checks if the index is equal to length of the string. If yes then we have esuccesfully found
    one permutation and we push it into the vector and return the function.
    */
    
    if(index >= s.length()){
        ans.push_back(s);
        return;
    }
    
    /*
    The for loop iteartes over the each character of the string. for character at index posititon, it allows to find the
    permutation with each character of the remaining string.

    The first swap() function swaps the index character with he current ith character and then we claa the funtion again recursively.
    The second swap() function is used to restore the orignal string since we are passing the
    string by reference. So any changes made to the string will be reflected in the orignal string too.
    
    */
    for(unsigned int i = index;i<s.length();i++){
        swap(s[index],s[i]);
        solve(index+1,s,ans);
        swap(s[index],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    int index = 0;
    vector<string> ans;
    solve(index,s,ans);
    return ans;
}

int main(){
    string s;

    cout<<"Enter the string : ";
    cin>>s;

    vector<string> ans = findPermutations(s);

    for(auto i : ans){
        cout<<i<<"   ";
    }
}