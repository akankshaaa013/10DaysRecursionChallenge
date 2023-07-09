#include <bits/stdc++.h> 
using namespace std;

void Solve(string &s,int n,int currIndex,string res,int resIndex,vector<string>& ans){
	
	/*
	if the currIndex is equal to n it basically indicates that the end f the string is reached and
	if resIndex is equal to 4 indicating a valid IP Address is formed the current res is pushed to ans vector after removing the trailing dot
	*/

	if(currIndex == n && resIndex == 4){
		if(res.size() > 0) res.pop_back();
		
		ans.push_back(res);
		return;
	}

	/*if the currIndex exceeds n or if the resIndex is greater than 4 we stop further processing since
	the IP Address formed is not valid and the function returns.*/

	if(currIndex >= n || resIndex > 4) return;
	
	/*
	If the current character at currIndex is '0' then we call the solve function for next character not before appending it
	to the current IP address along with '.'
	*/
	if(s[currIndex] == '0'){
		Solve(s,n,currIndex+1,res+s[currIndex]+".",resIndex+1,ans);
	}
	/*
	If the current character is not 0, we try all possible substring lengths starting from currIndex. If the extracted
	substring is less than or equal to 255 , we recursively call solve for the next index and increment resIndex, while
	appending the extracted substring and '.' with the res that stores the current state of the IP address.
	*/
	else{
		for(int i=1;i<=3 && i <= (n-currIndex);i++){
			string temp = s.substr(currIndex,i);

			if(stoi(temp) <= 255){
				Solve(s,n,currIndex+i,res+temp+".",resIndex+1,ans);
			}
		}
	}
}

vector<string> generateIPAddress(string s)
{
	vector<string> ans;
	string res = "";
	int n = s.length();
	
	Solve(s,n,0,"",0,ans);
	
	return ans;
}

int main(){
    string s;
    cout<<"Enter the string s : ";
    cin>>s;

    vector<string> ans = generateIPAddress(s);

    if(ans.empty()){
        cout<<"No valid IP Address is possible ";
    }
    else{
        for(auto i : ans){
            cout<<i<<endl;
        }
    }
}