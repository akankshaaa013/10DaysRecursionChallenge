#include <bits/stdc++.h> 
using namespace std;

void solve(string &s,unsigned int i,string& ans){

    /*Base case : If i is equal to length of the string then push the last character 
    into the ans string if and only if the ans string is not empty and atlast return.
    */
    
    if(i == s.length()){
        if(ans!="")
            ans.push_back(s[i]);
        return;
    }
    
    // checking if the current character is num or not. If yes then push the character into ans string
    // and again call the function recursive for the next index , else directly call the function recursively for next
    // index
    if((s[i] >= '0' && s[i] <= '9')){
        ans.push_back(s[i]);
        solve(s,i+1,ans);
    }
    solve(s,i+1,ans);
}

int atoi(string str) {

    int f = 1;
    if(str[0] == '-'){
        f = -1;
    }
    string ans;
    solve(str,0,ans);

    long long int num = 0;
    if(ans != ""){
        num = stoi(ans);
    }

    return f*num;

}

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    int ans = atoi(s);
    cout<<ans;
}