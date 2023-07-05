#include<bits/stdc++.h>
using namespace std;

void solve(string str,unsigned int index,string res,vector<string>& ans){

	if(index >= str.length()){
		if(res.length() > 0){
			ans.push_back(res);
		}
		return;
	}

	solve(str,index+1,res,ans);

	res+=str[index];
	solve(str,index+1,res,ans);
}

vector<string> subsequences(string str){
	
	string res="";
	vector<string> ans;

	int index = 0;

	solve(str,index,res,ans);

	return ans;
	
}

int main(){

    string s;


    cout<<"Enter the string : ";
    cin>>s;

    vector<string> ans = subsequences(s);

    for(auto i : ans){
        cout<<i<<"   ";
    }

}