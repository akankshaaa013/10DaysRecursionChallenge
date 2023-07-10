#include <bits/stdc++.h>
using namespace std;

void Solve(unsigned int index,string &str, vector<string> &ans,string temp,int count){

    // if index is equal to the length of the input string and count is greater than 0 then we contantenate temp string with count and 
    // push it in the ans vector and return the function.
    if(index==str.length()){

        if(count>0){
            temp+=to_string(count);
        }

        ans.push_back(temp);
        return;
    }

    // if count is greater than 0 then it appends the count to temp string along with the string at 
    // index position and calls the function recursively for next character of the string.

    if(count>0){
        Solve(index+1,str,ans,temp+to_string(count)+str[index],0);
    }
    // else if count is 0 then we append the current indexth character to the string and again call the 
    // function recursively for the next character.
    else{
        Solve(index+1,str,ans,temp+str[index],count);
    }
    //then another recursive call is made to process the next index with an incremented count.
    // This is done to generate abbreviations with conseutive characters being abbreviated together. 
    Solve(index+1,str,ans,temp,count+1);

    }

vector<string> findAbbr(string &str){

   vector<string> ans;
   
   string temp;

   Solve(0,str,ans,temp,0);
   
   sort(ans.begin(),ans.end());  

   return ans;

}

int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    vector<string> ans = findAbbr(s);

    for(auto i:ans){
        cout<<i<<"   ";
    }
}