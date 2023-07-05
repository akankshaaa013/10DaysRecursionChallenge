#include<bits/stdc++.h>
using namespace std;

void solve(string &s,unsigned int index, string &result, vector<string> &ans,string digToStr[]){

	/*
	If the length of the index is greater than or equal to input string 
	then we have succesfully generated one combination and we need to push
	the result string in the ans vector. After that the function returns.
	*/
	if(index >= s.length()){
		ans.push_back(result);
		return;
	}

	//Extracting the number from index position & subracting from '0' so that orignal num is restored.

	int num = s[index] - '0';
	
	//Finding the string mapped to num.
	string str = digToStr[num];

	// Iterating through each value of str and calling the function recursively for next index position.
	/*
	Once the character is pushed into the result string after the recursive calling we also need
	to restore the orignal string so we pop the last pushed character.
	*/
	for(unsigned int i=0;i<str.length();i++){
		result.push_back(str[i]);
		solve(s,index+1,result,ans,digToStr);
		result.pop_back();
	}
}

vector<string> combinations(string &s){
	
	string result = "";
	vector<string> ans;

	if(s.length() == 0){
		return ans;
	}

	string digToStr[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    int index = 0;

	solve(s,index,result,ans,digToStr);
	
	return ans;
	
}

int main(){
    string s;

    cout<<"Enter the string : ";
    cin>>s;

    vector<string> ans1 = combinations(s);

    for(auto i : ans1){
        cout<<i<<"   ";
    }
}